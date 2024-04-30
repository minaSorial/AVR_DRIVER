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







void SM_Init( State* SwitchStateTable,u8 SwitchStateSize, u8 initState ,u8* State);

void SM_execute(State*  SwitchStateTable ,u8* State);
#endif // SM_H_
