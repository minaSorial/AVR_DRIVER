#include "std_types.h"
#include "util/delay.h"
#include "DIO_int.h"

#include "STD_BITMAN.h"

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

void write_string(char data[],u8 size ){

	u8 i=0;
	for (i = 0; i < size; ++i) {

		write_data(data[i]);

	}


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




int main ( void){



DIO_vidInit();

	init();

	u8 writecmd= 0b10000000+0x40;

	write_command(writecmd);

	 write_data('T');


	 // importatnt
	 while(1){


	 }






	
	//u8 u8Switch1;

	//u8 u8Switch2;
	//DIO_enuGetPinValue(1,&u8Switch2);
	//u8 u8Switch3;
	//DIO_enuGetPinValue(2,&u8Switch3);

	//u8 u8num1=0;
	//u8 u8num2=0;
	//u8 u8result=0;
	//operation op= add;
	//s8 c= '+';
	

}
