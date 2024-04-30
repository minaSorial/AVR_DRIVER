#ifndef SM_H_
#define SM_H_

#include "STD_TYPES.h"

typedef void (*tpfnAction)(void);
typedef STD_Bool (*tpfnGaurd)(void);

typedef struct 
{
	u16 TransitionEntry;
	u8 u8NextStateIdx;
	tpfnGaurd pfnGaurd;
	u16 TransitionExit;
}tstrTransition;



typedef tstrTransition* pstrTransitionTable;

typedef struct
{
	u16 StateEntry;
	u8 StateId;
	tpfnAction SM_onEntry;
	tpfnAction SM_doAction;
	tpfnAction SM_onExit;
	u8 u8TransitonTableSize;
	pstrTransitionTable aTransitionTable;
	u16 StateExit;
}State;



typedef enum
{

    SW_preReleased,
    SW_pressed,
	SW_released,
	SW_prePressed
    
}SW_tenuStates;

STD_Bool bReleaseToPrepressedGaurd(void);
/*
{
	return STD_true;
}*/


void vidReleasedOnEntry(void);
void vidReleasedOnAction(void);








void SM_Init( State* SwitchStateTable,u8 SwitchStateSize, u8 initState ,u8* State);

void SM_execute(State*  SwitchStateTable ,u8* State);
#endif // SM_H_
