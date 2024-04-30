// Component Name SM

//1- State Table
typedef void (*tpfnAction)(void);
typedef STD_Bool (*tpfnGaurd)(void);

typedef struct 
{
	u16 TransitionEntry;
	u8 u8NextStateIdx;
	tpfnGaurd pfnGaurd;
	u16 TransitionExit;
}tstrTransition;
typedef struct
{
	u16 StateEntry;
	
	u8 StateIdx;
	tpfnAction SM_onEntry;
	tpfnAction SM_doAction;
	tpfnAction SM_onExit;
	u8 u8TransitonTableSize;
	pstrTransitionTable aTransitionTable;
	u16 StateExit;
}State;	

typedef enum
{
	SW_Released,
	SW_prePressed,
	
}SW_tenuStates;

STD_Bool bReleaseToPrepressedGaurd(void)
{
	return STD_TRUE;
}
tstrTransition transitionTable[] = 
{
	{
	.TransitionEntry = 0xAA55,
	.u8NextStateIdx = SW_prePressed,
	.pfnGaurd = bReleaseToPrepressedGaurd,
	.TransitionExit = 0x55AA,
	},
	{
	.TransitionEntry = 0xAA55,
	.u8NextStateIdx = SW_pressed,
	.pfnGaurd = bReleaseToPrepressedGaurd,
	.TransitionExit = 0x55AA,	
	}
};


void vidReleasedOnEntry(void)
{
	
	
}

State SwitchStateTable[]
{
	{
		.StateEntry = 0xAA55
		.StateIdx =(u8)SW_Released;
		.SM_onEntry = vidReleasedOnEntry;
		.SM_DoAction = vidReleasedonEntry;
		.SM_onExit = STD_NULL;
		.u8TransitonTableSize = sizeof(aTransitionTable)/sizeof(transitionTable);
		.transitionTable = aTransitionTable;
		
		
		.StateExit = 0x55AA
	},
	{
		
	}
}

SM_Init(SwitchStateTable,u8 initState,u8* State);

SM_execute(SwitchStateTable,u8* State);