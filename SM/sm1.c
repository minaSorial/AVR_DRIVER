/*
 * sm1.c
 *
 *  Created on: 20 Aug 2023
 *      Author: Mizoo
 */

#include "STD_TYPES.h"
#include "SM.h"


tstrTransition trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = SW_prePressed,
				.pfnGaurd = bReleaseToPrepressedGaurd,
				.TransitionExit = 0x55AA
		},

		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = SW_pressed,
				.pfnGaurd = bReleaseToPrepressedGaurd,
				.TransitionExit = 0x55AA,
		}
};

State SwitchStateTabl []={{
		   .StateEntry = 0xAA55,
		   .StateId =(u8)SW_pressed,
		   .SM_onEntry = vidReleasedOnEntry,
		   .SM_doAction = vidReleasedOnAction,
		   .SM_onExit = STD_NULL,
		   .aTransitionTable = trasitionTable,
		   .u8TransitonTableSize = sizeof(trasitionTable)/sizeof(tstrTransition),
		   .StateExit = 0x55AA,
}  };


STD_Bool bReleaseToPrepressedGaurd(void)
{
	return STD_true;
}


void vidReleasedOnEntry(void){}
void vidReleasedOnAction(void){}





