#include "STD_TYPES.h"
#include "SM.h"



void SM_Init( State* SwitchStateTable,u8 SwitchStateSize, u8 initState ,u8* State){

	u8 i = 0;
	for(i=0;i<SwitchStateSize;i++){

		if(SwitchStateTable[i].StateId== initState){

			*State=i;
			if(SwitchStateTable[i].SM_onEntry == STD_NULL){

			}
			else{
				SwitchStateTable[i].SM_onEntry();
			}

			break;
		}
		else{


		}
	}



}

void SM_execute(State*  SwitchStateTable ,u8* state){

	State* Current_state = &SwitchStateTable[*state];
	;


	u8 i=0;
	STD_Bool trasition=STD_false;

	for(i=0;i<Current_state->u8TransitonTableSize;i++){

		if(Current_state->aTransitionTable[i].pfnGaurd!=STD_NULL){

			if(Current_state->aTransitionTable[i].pfnGaurd()== STD_true){

				trasition=STD_true;

				if(Current_state->SM_onExit == STD_NULL){

				}
				else{
					Current_state->SM_onExit();
				}

				*state=Current_state->aTransitionTable[i].u8NextStateIdx;


				if(SwitchStateTable[*state].SM_onEntry == STD_NULL){

				}
				else{
					SwitchStateTable[*state].SM_onEntry();
				}

				break;

			}else{}

		}else{

		}

	}
	if(trasition==STD_false){

		if (Current_state->SM_doAction == STD_NULL) {

		}
		else {
			Current_state->SM_doAction();


		}


	}else{


	}



	return;
}





