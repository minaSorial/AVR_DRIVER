/*
 * RTOS_cfg.c
 *
 *  Created on: 13 Nov 2023
 *      Author: Mizoo
 */
#include "STD_TYPES.h"
#include "RTOS_int.h"
#include "RTOS_cfg.h"


void blink1000(void);
void blink500(void);
void blink250(void);




RTOS_Task task1 = {.first_dlay=0,.period=1000,.pfun=blink1000,.enable_flag=STD_true};
RTOS_Task task2 = {.first_dlay=250,.period=500,.pfun=blink500,.enable_flag=STD_true};
RTOS_Task task3 = {.first_dlay=375,.period=250,.pfun=blink250,.enable_flag=STD_true};

RTOS_Task *task_tabele[RTOS_TASK_NUM]={&task1,&task2,&task3};


