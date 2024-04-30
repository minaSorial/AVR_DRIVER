/*
 * main.c
 *
 *  Created on: 2 Aug 2023
 *      Author: Mizoo
 */

#include "std_types.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "STD_BITMAN.h"

static const  u8 u8SevenSegment[]=

{
    0b00111111, //0

    0b00000110, //1

    0b01011011,

    0b01001111,

    0b01100110,

    0b01101101,

    0b01111101,//6

    0b00000111,

    0b01111111,

    0b01101111

};



int main(void){

	DIO_vidInit();
	//u8 u8CurrentLED=0;
	u8 index=0;

	while(1){


		u8 u8Switch1;
		DIO_enuGetPinValue(0,&u8Switch1);


		u8 u8Switch2;
		DIO_enuGetPinValue(1,&u8Switch2);

		//DIO_enuSetPortValue(0, u8Switch2);





		if(u8Switch1==DIO_LOW)

				{
					_delay_ms(300);

					index++;

					if(index>=20)

					{

						index=0;

					}else

					{

					   //Do Nothing

					}

				}else if(u8Switch2==DIO_LOW)

				{

					_delay_ms(300);


					if(index>0)

					{

						index--;

					}else

					{

						index=20;

					}




				}



				DIO_enuSetPinValue(2,DIO_LOW);

				DIO_enuSetPortValue(0, u8SevenSegment[index/10]);

				_delay_ms(5);

				DIO_enuSetPinValue(2,DIO_HIGH);

				DIO_enuSetPinValue(3,DIO_LOW);

				DIO_enuSetPortValue(0, u8SevenSegment[index%10]);

				_delay_ms(5);

				DIO_enuSetPinValue(3,DIO_HIGH);



			//int index =0;
/*
		for (index=0 ; index<10;index++){


			DIO_enuSetPortValue(0, u8SevenSegment[index]);
			_delay_ms(200);
		}
*/



		/*

		DIO_enuSetPinValue(2,DIO_LOW);

		DIO_enuSetPortValue(0, u8SevenSegment[5]);

		_delay_ms(5);

		DIO_enuSetPinValue(2,DIO_HIGH);

		DIO_enuSetPinValue(3,DIO_LOW);

		DIO_enuSetPortValue(0, u8SevenSegment[6]);

		_delay_ms(5);

		DIO_enuSetPinValue(3,DIO_HIGH);


*/













	}

}




