/*
 * sm1.c
 *
 *  Created on: 20 Aug 2023
 *      Author: Mizoo
 */

#include "STD_TYPES.h"
#include "SM.h"
#include<stdio.h>
#include<conio.h>

typedef enum { A, B, C, D} stateId; 

s8 GLOB; 

void  A_OnEntry(void){

			printf(" %s",__func__);

}
void  B_OnEntry(void){

			printf(" %s",__func__);

}
void  C_OnEntry(void){

		printf(" %s",__func__);
		

}
void  D_OnEntry(void){

			printf(" %s",__func__);

}


void  A_OnExit(void){

			printf(" %s",__func__);

}
void  B_OnExit(void){

			printf(" %s",__func__);

}
void  C_OnExit(void){

			printf(" %s",__func__);

}
void  D_OnExit(void){

			printf(" %s",__func__);

}


void  A_doAction(void){

			printf(" %s",__func__);

}
void  B_doAction(void){

			printf(" %s",__func__);

}
void  C_doAction(void){

			printf(" %s",__func__);

}
void  D_doAction(void){

			printf(" %s",__func__);

}




STD_Bool A_B_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='B'){
		result= STD_true;
	}
	return result;
}

STD_Bool A_C_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='C'){
		result= STD_true;
	}
	return result;
}



tstrTransition A_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = B,
				.pfnGaurd = A_B_Gaurd,
				.TransitionExit = 0x55AA
		},

		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = C,
				.pfnGaurd = A_C_Gaurd,
				.TransitionExit = 0x55AA,
		}


};

STD_Bool B_A_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='A'){
		result= STD_true;
	}
	return result;
}

STD_Bool B_C_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='C'){
		result= STD_true;
	}
	return result;
}








tstrTransition B_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = C,
				.pfnGaurd = B_C_Gaurd,
				.TransitionExit = 0x55AA
		},

		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = A,
				.pfnGaurd = B_A_Gaurd,
				.TransitionExit = 0x55AA,
		}


};


STD_Bool C_A_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='A'){
		result= STD_true;
	}
	return result;
}

STD_Bool C_B_Gaurd( ){

	STD_Bool result = STD_false;
	if (GLOB=='B'){
		result= STD_true;
	}
	return result;
}



tstrTransition C_trasitionTable[] =
{
		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = A,
				.pfnGaurd = C_A_Gaurd,
				.TransitionExit = 0x55AA
		},

		{
				.TransitionEntry = 0xAA55,
				.u8NextStateIdx = B,
				.pfnGaurd = C_B_Gaurd,
				.TransitionExit = 0x55AA,
		}


};









State SwitchStateTabl []={{
		   .StateEntry = 0xAA55,
		   .StateId =(u8)A,
		   .SM_onEntry = A_OnEntry,
		   .SM_doAction = A_doAction,
		   .SM_onExit = A_OnExit,
		   .aTransitionTable = A_trasitionTable,
		   .u8TransitonTableSize = sizeof(A_trasitionTable)/sizeof(tstrTransition),
		   .StateExit = 0x55AA,
}, 
{
		   .StateEntry = 0xAA65,
		   .StateId =(u8)B,
		   .SM_onEntry = B_OnEntry,
		   .SM_doAction = B_doAction,
		   .SM_onExit = B_OnExit,
		   .aTransitionTable = B_trasitionTable,
		   .u8TransitonTableSize = sizeof(B_trasitionTable)/sizeof(tstrTransition),
		   .StateExit = 0x56AA,
},
{
		   .StateEntry = 0xAA58,
		   .StateId =(u8)C,
		   .SM_onEntry = C_OnEntry,
		   .SM_doAction = C_doAction,
		   .SM_onExit = C_OnExit,
		   .aTransitionTable = C_trasitionTable,
		   .u8TransitonTableSize = sizeof(C_trasitionTable)/sizeof(tstrTransition),
		   .StateExit = 0x59AA,
}  




};


int main(void){ 


	u8 currState=0;

	SM_Init(SwitchStateTabl,3,A,&currState);

	while (GLOB!='e')
	{
		GLOB=getch();
		SM_execute(SwitchStateTabl,&currState);


	}
	




	return 0;
}














