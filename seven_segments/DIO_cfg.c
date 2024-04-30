/*
 * DIO_cfg.c
 *
 *  Created on: 28 Jul 2023
 *      Author: Mizoo
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "DIO_cfg.h"


const DIO_tstrPIN DIO_kastrPinCg [DIO_PIN_NUM]={
		{DIO_PORTD,DIO_PIN0,DIO_INPUT, DIO_NOT_USED, DIO_PULLUP },
		{DIO_PORTD,DIO_PIN1,DIO_INPUT, DIO_NOT_USED, DIO_PULLUP },

		{DIO_PORTD,DIO_PIN4,DIO_OUTPUT, DIO_HIGH, DIO_NOT_USED },
		{DIO_PORTD,DIO_PIN5,DIO_OUTPUT, DIO_HIGH, DIO_NOT_USED }

     };

const DIO_tstrPORT DIO_kastrPortCg[DIO_PORT_NUM]={

		{ DIO_PORTA,
			 .u8Mask=255,
			 .u8Direction=255,
			 .u8InitValue=0,
			 .u8InputMode=DIO_NOT_USED
			},

};







