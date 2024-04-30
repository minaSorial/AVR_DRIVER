/*
 * main.c
 *
 *  Created on: 8 Aug 2023
 *      Author: Mizoo
 */

#include "std_types.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "SM.h"

#include "STD_BITMAN.h"

// pin 4 = Rs
// pin 5 = Rw
// pin 6 = Enable
static const  u8 u8numAsci[]=

{
		'0', //0
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9',
};

typedef enum {add, sub,multi, div}operation;

typedef struct{

	u8 num1;
	operation op;
	u8 num2;
	u8 result;
} strData;

strData data;



typedef enum { first, oper, second, result} stateId;
//static  u8 u8ArrCalcData[3];

void init()
{
	_delay_ms(50);

	write_command(0b00111000);

	_delay_ms(5);
	//enable display,no curser,not blinking

	write_command(0b00001100);
	_delay_ms(5);

	//clear display
	write_command(0b00000001);
	_delay_ms(5);


}


void write_command(u8 command)
{
	// enable
	DIO_enuSetPinValue(5, DIO_LOW);

	//RS
	DIO_enuSetPinValue(3,DIO_LOW);
	//RW
	DIO_enuSetPinValue(4,DIO_LOW);


	DIO_enuSetPortValue(0,command);


	DIO_enuSetPinValue(5, DIO_HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(5, DIO_LOW);


}







void write_data(u8 data)
{


	// enable
	DIO_enuSetPinValue(5, DIO_LOW);

	//RS
	DIO_enuSetPinValue(3,DIO_HIGH);
	//RW
	DIO_enuSetPinValue(4,DIO_LOW);


	DIO_enuSetPortValue(0,data);


	DIO_enuSetPinValue(5, DIO_HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(5, DIO_LOW);

}


void incrementDecrement(u8*num){
	u8 u8Switch1;

	u8 u8Switch2;
	DIO_enuGetPinValue(0,&u8Switch1);
	DIO_enuGetPinValue(1,&u8Switch2);
	//DIO_enuGetPinValue(2,&u8Switch3);


	if(u8Switch1==DIO_LOW)

	{
		_delay_ms(300);

		(*num)++;

		if((*num)>=10)

		{

			(*num)=0;

		}else

		{

			//Do Nothing

		}

	}else if(u8Switch2==DIO_LOW)

	{

		_delay_ms(300);


		if((*num)>0)

		{

			(*num)--;

		}else

		{

			(*num)=9;

		}

	}





}

void choseOperation(operation * op){

	u8 u8Switch1;

	u8 u8Switch2;
	DIO_enuGetPinValue(0,&u8Switch1);
	DIO_enuGetPinValue(1,&u8Switch2);
	//DIO_enuGetPinValue(2,&u8Switch3);
	u8 index=(u8)(*op);


	if(u8Switch1==DIO_LOW)

	{
		_delay_ms(300);

		index++;

		if((index)>=4)

		{

			(index)=0;

		}else

		{

			//Do Nothing

		}

	}else if(u8Switch2==DIO_LOW)

	{

		_delay_ms(300);


		if((index)>0)

		{

			(index)--;

		}else

		{

			(index)=3;

		}

	}


	switch (index){

	case 0 :
		*op = add;
		break;
	case 1 :
		*op = sub;
		break;
	case 2 :
		*op = multi;
		break;
	case 3 :
		*op = div;
		break;
		//default:
		//	*op = add;


	}

	return;
}

s8 opToChar(operation op){

	s8 c='0';

	switch (op){

	case add :
		c = '+';
		break;
	case sub :
		c = '-';
		break;
	case multi :
		c = '*';
		break;
	case div :
		c = '/';
		break;
	default:
		c = '0';


	}



	return c;
}

STD_Bool transition_gurad( ){

	STD_Bool result = STD_false;
	u8 u8Switch3;
	DIO_enuGetPinValue(2,&u8Switch3);
	if(u8Switch3==DIO_LOW){
		_delay_ms(300);
		result= STD_true;
	}
	return result;
}


tstrTransition first_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = oper,
				.pfnGaurd = transition_gurad,
				.TransitionExit = 0x55AA
		},
};

tstrTransition operation_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = second,
				.pfnGaurd = transition_gurad,
				.TransitionExit = 0x55AA
		},
};
tstrTransition second_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = result,
				.pfnGaurd = transition_gurad,
				.TransitionExit = 0x55AA
		},
};

tstrTransition result_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = first,
				.pfnGaurd = transition_gurad,
				.TransitionExit = 0x55AA
		},
};

void first_OnEntry(void){

	data.num1=0;

	write_command(0b00000001);
	write_data(u8numAsci[data.num1]);


}

void first_doAction(void){

	u8 u8num1=data.num1;
	incrementDecrement(&u8num1);
	data.num1=u8num1;
	write_command(0b00000001);
	_delay_ms(50);
	write_data(u8numAsci[data.num1]);
	_delay_ms(50);
}

void first_OnExit(){


}



void oper_OnEntry(void){

	data.op= add;

	write_command(0b00000001);
	write_data(u8numAsci[data.num1]);
	write_data('+');



}

void oper_doAction(void){

	//u8 u8num1=0;
	operation op=data.op;
	choseOperation(&op);
	data.op=op;

	write_command(0b00000001);
	//_delay_ms(100);
	write_data(u8numAsci[data.num1]);

	s8 c=opToChar(data.op);

	write_data(c);
	_delay_ms(50);
}

void oper_OnExit(){


}


void second_OnEntry(void){

	data.num2=0;

	write_command(0b00000001);

	write_data(u8numAsci[data.num1]);

	s8 c=opToChar(data.op);

	write_data(c);
	write_data(u8numAsci[data.num2]);


}

void second_doAction(void){

	u8 u8num2=data.num2;
	incrementDecrement(&u8num2);
	data.num2=u8num2;
	write_command(0b00000001);
	//_delay_ms(100);
	write_data(u8numAsci[data.num1]);
	s8 c=opToChar(data.op);

	write_data(c);
	write_data(u8numAsci[data.num2]);
	_delay_ms(50);
}

void second_OnExit(){


}



void result_OnEntry(void){



	write_command(0b00000001);

	write_data(u8numAsci[data.num1]);

	s8 c=opToChar(data.op);

	write_data(c);
	write_data(u8numAsci[data.num2]);
	write_data('=');
	_delay_ms(50);



}

void result_doAction(void){

	u8 results;

	operation op=data.op;



	switch (op){

	case add :
		results = data.num1+data.num2;
		break;
	case sub :
		results = data.num1-data.num2;
		break;
	case multi :
		results = data.num1*data.num2;
		break;
	case div :
		if(data.num2 !=0){
			results = data.num1/data.num2;
		}
		else {
			results = 'N';
		}
		break;
	default:
		results = 'N';


	}

	data.result=results;
	write_command(0b00000001);
	_delay_ms(50);

	write_data(u8numAsci[data.num1]);

	s8 c=opToChar(data.op);

	write_data(c);
	write_data(u8numAsci[data.num2]);
	write_data('=');
	//_delay_ms(50);
	if(data.result !='N'){
		write_data(u8numAsci[data.result/10]);
		write_data(u8numAsci[data.result%10]);
	}else {
		write_data(data.result);
	}

	_delay_ms(50);


}

void result_OnExit(){



}







State SwitchStateTabl []={{
		.StateEntry = 0xAA55,
		.StateId =(u8)first,
		.SM_onEntry = first_OnEntry,
		.SM_doAction = first_doAction,
		.SM_onExit =  first_OnExit,
		.aTransitionTable = first_trasitionTable,
		.u8TransitonTableSize = sizeof(first_trasitionTable)/sizeof(tstrTransition),
		.StateExit = 0x55AA,
},
		{
				.StateEntry = 0xAA65,
				.StateId =(u8)oper,
				.SM_onEntry = oper_OnEntry,
				.SM_doAction = oper_doAction,
				.SM_onExit = oper_OnExit,
				.aTransitionTable = operation_trasitionTable,
				.u8TransitonTableSize = sizeof(operation_trasitionTable)/sizeof(tstrTransition),
				.StateExit = 0x56AA,
		},
		{
				.StateEntry = 0xAA58,
				.StateId =(u8)second,
				.SM_onEntry = second_OnEntry,
				.SM_doAction = second_doAction,
				.SM_onExit = second_OnExit,
				.aTransitionTable = second_trasitionTable,
				.u8TransitonTableSize = sizeof(second_trasitionTable)/sizeof(tstrTransition),
				.StateExit = 0x59AA,
		},

		{
				.StateEntry = 0xAA58,
				.StateId =(u8)result,
				.SM_onEntry = result_OnEntry,
				.SM_doAction = result_doAction,
				.SM_onExit = result_OnExit,
				.aTransitionTable = result_trasitionTable,
				.u8TransitonTableSize = sizeof(result_trasitionTable)/sizeof(tstrTransition),
				.StateExit = 0x59AA,
		}






};









int main(void){

	DIO_vidInit();

	init();
	u8 currstate;

	SM_Init(SwitchStateTabl,3,first ,&currstate);



	//write_data('T');

	/*
	u8 u8Switch1;

	u8 u8Switch2;
	//DIO_enuGetPinValue(1,&u8Switch2);
	u8 u8Switch3;
	//DIO_enuGetPinValue(2,&u8Switch3);

	u8 u8num1=0;
	u8 u8num2=0;
	u8 u8result=0;
	operation op= add;
	s8 c= '+';
	 */

	while(1){
		//DIO_enuGetPinValue(0,&u8Switch1);
		//DIO_enuGetPinValue(1,&u8Switch2);
		//DIO_enuGetPinValue(2,&u8Switch3);


		//incrementDecrement(&u8num1);


		//choseOperation(&op);

		//c= opToChar(op);



		/*	}else if (u8Switch3==DIO_LOW){
			_delay_ms(300);
			write_data('+');
		}
		 */


		//_delay_ms(300);
		//_delay_ms(50);

		// set address


		//write_command(0b00000001);
		//_delay_ms(100);

		//write_data(u8numAsci[u8num1]);
		//write_data(c);
		//_delay_ms(50);

		SM_execute(SwitchStateTabl,&currstate);



	}







	return 0;
}

