/*
 * DIO_prg.c
 *
 *  Created on: 28 Jul 2023
 *      Author: Mizoo
 */

#include "STD_TYPES.h"
#include "STD_BITMAN.h"
#include "DIO_reg.h"
#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_prv.h"


static u8*  const u8KarrPorts []={&PORTA, &PORTB, &PORTC, &PORTD};
static u8*  const u8KarrDdra  []={&DDRA, &DDRB, &DDRC, &DDRD};
static u8*  const u8KarrPins  []={&PINA, &PINB, &PINC, &PIND};


void DIO_vidInit(void){

	// Priority to ports






	u8 u8PinIdxLoc=0;

	for (u8PinIdxLoc = 0; u8PinIdxLoc < DIO_PIN_NUM; ++u8PinIdxLoc) {


		const DIO_tstrPIN * pstrCurrentPinLoc = & DIO_kastrPinCg[u8PinIdxLoc];

		if(pstrCurrentPinLoc->u8Direction==DIO_OUTPUT){

			BIT_SET(* u8KarrDdra [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);



			if(pstrCurrentPinLoc->u8InitValue==DIO_HIGH){

				BIT_SET(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);

			}

			else{

				BIT_CLEAR(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);


			}

		}

		else if(pstrCurrentPinLoc->u8Direction==DIO_INPUT){

			BIT_CLEAR(* u8KarrDdra [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);



			if(pstrCurrentPinLoc->u8InputMode==DIO_PULLUP){

				BIT_SET(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);

			}

			else{

				BIT_CLEAR(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);


			}


		}

	}




	u8 u8PortNumLoc=0;

	    u8 u8BitIdx;

	    for (u8PortNumLoc = 0; u8PortNumLoc < DIO_PORT_NUM; ++u8PortNumLoc) {





	        const DIO_tstrPORT * pstrCurrentPortLoc = & DIO_kastrPortCg[u8PortNumLoc];



	        *(u8KarrDdra[pstrCurrentPortLoc->u8PortIdx])= pstrCurrentPortLoc->u8Direction & pstrCurrentPortLoc->u8Mask;



	        for(u8BitIdx=0;u8BitIdx<8;u8BitIdx++)

	        {

	            if( (BIT_GET(((pstrCurrentPortLoc->u8Direction) & (pstrCurrentPortLoc->u8Mask)),u8BitIdx))==DIO_INPUT)

	            {

	                BIT_ASSGIN((*u8KarrPorts[pstrCurrentPortLoc->u8PortIdx]),u8BitIdx,(pstrCurrentPortLoc->u8InputMode & pstrCurrentPortLoc->u8Mask));

	            }else{

	                BIT_ASSGIN((*u8KarrPorts[pstrCurrentPortLoc->u8PortIdx]),u8BitIdx,(pstrCurrentPortLoc->u8InitValue & pstrCurrentPortLoc->u8Mask));



	            }

	        }





	    }







}


STD_tenuReturn DIO_enuSetPinValue(u8 u8PinIdxCpy,u8 u8ValueCpy){



	STD_tenuReturn status;

	if( u8PinIdxCpy>=DIO_PIN_NUM  ){

		status=STD_enuOutOfRange;

	}
	else if( (u8ValueCpy!=DIO_HIGH)&&(u8ValueCpy!=DIO_LOW) ){

		status=STD_enuNOK;


	}

	else
	{


		const DIO_tstrPIN *pstrCurrentPinLoc=&DIO_kastrPinCg[u8PinIdxCpy];

		if(u8ValueCpy==DIO_HIGH){
			BIT_SET(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);
		}
		else{
			BIT_CLEAR(* u8KarrPorts [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);
		}

		status=STD_enuOK;


	}



	return  status ;
}




STD_tenuReturn DIO_enuGetPinValue(u8 u8PinIdxCpy,u8 * pu8ValueCpy){

	STD_tenuReturn status;


	if( u8PinIdxCpy>=DIO_PIN_NUM  ){

		status=STD_enuOutOfRange;

	}else if(pu8ValueCpy==STD_NULL){

		status= STD_enuNullPtr;

	}
	else
	{
		const DIO_tstrPIN *pstrCurrentPinLoc=&DIO_kastrPinCg[u8PinIdxCpy];

		u8 temp = BIT_GET(*u8KarrPins [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);



		if( (temp==0)){

			*pu8ValueCpy=DIO_LOW;

			//status=STD_enuNOK;

		}
		else{
			*pu8ValueCpy=DIO_HIGH;



		}

		status=STD_enuOK;

	}
	return  status ;
}


/*Discrtiption:
	Set the specified PIN with the Direction given.
Input:
	u8PinIdxCpy: PIN index from the Configured PINS.
	u8DirCpy: Dir to be give.
Return: retutn execution State.
		STD_enuOK,
		STD_enuOutOfRange
		STD_enuNOK.

 */
STD_tenuReturn DIO_enuSetPinDirection(u8 u8PinIdxCpy,u8 u8DirCpy){

	STD_tenuReturn status;

	if( u8PinIdxCpy>=DIO_PIN_NUM  ){

		status=STD_enuOutOfRange;

	}
	else if( (u8DirCpy!=DIO_INPUT)&&(u8DirCpy!=DIO_OUTPUT) ){

		status=STD_enuNOK;

	}

	else
	{

		const DIO_tstrPIN *pstrCurrentPinLoc=&DIO_kastrPinCg[u8PinIdxCpy];

		if(u8DirCpy==DIO_OUTPUT){
			BIT_SET(* u8KarrDdra [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);
			//pstrCurrentPinLoc->u8Direction=DIO_OUTPUT;
		}
		else{
			BIT_CLEAR(* u8KarrDdra [pstrCurrentPinLoc->u8PortIdx ] ,  pstrCurrentPinLoc->u8PinIdx);
			//pstrCurrentPinLoc->u8Direction=DIO_INPUT;

		}

		status=STD_enuOK;


	}



	return  status ;
}



STD_tenuReturn DIO_enuSetPortValue(u8 u8PortIdxCpy,u8 u8ValueCpy){

	/*Discrtiption:
			Set the specified Port with the Value given.
		Input:
			u8PortIdxCpy: Port index from the Configured PORT.
			u8ValueCpy: Value to be give.
		Return: retutn execution State.
				STD_enuOK,
				STD_enuOutOfRange
				STD_enuNOK.

	 */

	STD_tenuReturn status;

	if( u8PortIdxCpy>=DIO_PORT_NUM  ){

		status=STD_enuOutOfRange;

	}
	else{

		const DIO_tstrPORT *pstrCurrentPORTLoc= &DIO_kastrPortCg[u8PortIdxCpy];

		* u8KarrPorts[pstrCurrentPORTLoc->u8PortIdx]= u8ValueCpy & pstrCurrentPORTLoc->u8Mask;
		status=STD_enuOK;

	}

	return status;
}




/*Discrtiption:
			Set the specified PIN with the Value given.
		Input:
			u8PortIdxCpy: Port index from the Configured PORT.
			pu8ValueCpy: pointer to read the value.
		Return: retutn execution State.
				STD_enuOK,
				STD_enuOutOfRange*/

STD_tenuReturn DIO_enuGetPortValue(u8 u8PortIdxCpy,u8 * pu8ValueCpy){

	STD_tenuReturn status;


	if( u8PortIdxCpy>=DIO_PORT_NUM  ){

		status=STD_enuOutOfRange;

	}
	else if(pu8ValueCpy==STD_NULL){

		status= STD_enuNullPtr;

	}
	else {

		//u8 * temptr=
		const DIO_tstrPORT *pstrCurrentPORTLoc= &DIO_kastrPortCg[u8PortIdxCpy];

		*pu8ValueCpy= *u8KarrPins[pstrCurrentPORTLoc->u8PortIdx];
		status= STD_enuOK;

	}

	return status;
}



STD_tenuReturn DIO_enuSetPortDirecrion(u8 u8PortIdxCpy,u8 u8DirCpy){
	/*	Discrtiption:
			Set the specified Port with the Value given.
		Input:
			u8PortIdxCpy: Port index from the Configured PORT.
			u8DirCpy: Direction to be give.
		Return: retutn execution State.
				STD_enuOK,
				STD_enuOutOfRange
				STD_enuNOK.
	 */

	STD_tenuReturn status;

	if( u8PortIdxCpy>=DIO_PORT_NUM  ){

		status=STD_enuOutOfRange;

	}
	else{

		const DIO_tstrPORT *pstrCurrentPORTLoc= &DIO_kastrPortCg[u8PortIdxCpy];

		* u8KarrDdra[pstrCurrentPORTLoc->u8PortIdx]= u8DirCpy & pstrCurrentPORTLoc->u8Mask;
		status=STD_enuOK;


	}

	return status;

}
















