/*
 * main.c
 *
 *  Created on: 29 Jul 2023
 *      Author: Mizoo
 */


/*
 * main.c
 *
 *  Created on: 27 Jul 2023
 *      Author: Mizoo
 */
#include "std_types.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "STD_BITMAN.h"



int main(void){

	DIO_vidInit();
	u8 u8CurrentLED=0;

/*	while(1){
		//u64 i;

		//u8 status;
		//status=BIT_GET(PINA,7);

		u8 u8Switch1;
		DIO_enuGetPinValue(3,&u8Switch1);

		u8 u8Switch2;
		DIO_enuGetPinValue(4,&u8Switch2);




		if(u8Switch1==DIO_LOW)

		{
			DIO_enuSetPinValue(u8CurrentLED,DIO_LOW);

			_delay_ms(200);

			u8CurrentLED++;

			if(u8CurrentLED>=3)

			{

				u8CurrentLED=0;

			}else

			{

				//Do Nothing

			}

		}else if(u8Switch2==DIO_LOW)

		{

			_delay_ms(200);
			DIO_enuSetPinValue(u8CurrentLED,DIO_LOW);

			if(u8CurrentLED>0)

			{

				u8CurrentLED--;

			}else

			{

				u8CurrentLED=2;

			}



		}



		if(u8Switch1==DIO_LOW || u8Switch2  ==DIO_LOW)

		{

			DIO_enuSetPinValue(u8CurrentLED,DIO_HIGH);

		}





	}
*/






	while(1){

		u8 switch_status=0;
		DIO_enuGetPortValue(1, &switch_status);


		u8 u8Switch1=BIT_GET(switch_status,0);
		//DIO_enuGetPinValue(3,&u8Switch1);
		u8 u8Switch2=BIT_GET(switch_status,1);

		 DIO_enuSetPortValue(0,u8Switch1);


/*
		  if(u8Switch1==DIO_LOW)

		  	  {
			     DIO_enuSetPortValue(0,0);


		            _delay_ms(100);

		            u8CurrentLED++;

		            if(u8CurrentLED>=3)

		            {

		                u8CurrentLED=0;

		            }else

		            {

		                //Do Nothing

		            }

		        }else if(u8Switch2==DIO_LOW)

		        {
		        	DIO_enuSetPortValue(0,0);

		            _delay_ms(100);

		            if(u8CurrentLED>0)

		            {

		                u8CurrentLED--;

		            }else

		            {

		                u8CurrentLED=0;

		            }



		        }


		          u8 u8PortValue = 1<<u8CurrentLED;


		        if(u8Switch1==DIO_LOW || u8Switch2  ==DIO_LOW)

		            {

		                DIO_enuSetPortValue(0,u8PortValue);

		            }






*/
	}


	return 0;
}

