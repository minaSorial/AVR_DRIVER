/*
 * main.c
 *
 *  Created on: 27 Jul 2023
 *      Author: Mizoo
 */
#include "std_types.h"
#include "DIO_reg.h"
#include "util/delay.h"
#include "STD_BITMAP.h"

int main(void){



	DDRA= 0B00000001;
    PORTA=0B10000000;
	//PINA

	//PORTA=0B00000001;

	while(1){
		//u64 i;

		u8 status;
		status=BIT_GET(PINA,7);

		if (status==0) {
			_delay_ms(200);
			 BIT_FLIP(PORTA,0);
		}
		//else
			//BIT_CLEAR(PORTA,0);



//		for (i=0 ; i <8000;i++) {
//
//		}

		//PORTA=0B00000000;
		//_delay_ms(500);

//		for (i=0 ; i <8000;i++) {
//
//		}




	}

 return 0;
}

