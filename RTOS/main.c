#include "std_types.h"

#include "DIO_int.h"

#include "STD_BITMAN.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "RTOS_int.h"



void blink1000(void){

	static u8 led_state=DIO_LOW;

	if(led_state==DIO_LOW){
		led_state=DIO_HIGH;
	}
	else{
		led_state=DIO_LOW;
	}

	DIO_enuSetPinValue(3,led_state);


}
void blink500(void){

	static u8 led_state=DIO_LOW;

	if(led_state==DIO_LOW){
		led_state=DIO_HIGH;
	}
	else{
		led_state=DIO_LOW;
	}

	DIO_enuSetPinValue(4,led_state);



}
void blink250(void){

	static u8 led_state=DIO_LOW;

	if(led_state==DIO_LOW){
		led_state=DIO_HIGH;
	}
	else{
		led_state=DIO_LOW;
	}

	DIO_enuSetPinValue(5,led_state);



}



void Timer1_Init(){



	// timer_1 16 bit
	BIT_CLEAR(TCCR1A,WGM10);
	BIT_CLEAR(TCCR1A,WGM11);

	BIT_SET(TCCR1B,WGM12);
	BIT_CLEAR(TCCR1B,WGM13);


	BIT_SET(TCCR1B,CS10);
	BIT_CLEAR(TCCR1B,CS12);
	BIT_SET(TCCR1B,CS11);

	BIT_SET(TIMSK,OCIE1A);

	OCR1A=124;

}


u8 timer_counter=1;

void (*pfun)(void);

/*
void ISR_callBack1( void ){

	timer_counter--;
}
 */


ISR(TIMER1_COMPA_vect)
{


	if(pfun){
		pfun();
	}else{

	}
}





int main ( void){

	pfun=RTOS_sysTick;


	DIO_vidInit();
	Timer1_Init();
	RTOS_vidInit();
	BIT_SET(SREG,SREG_I);

	 RTOS_startRTOS();

	 RTOS_disable_task(1);

	while(1){

		RTOS_schadular();
	}
}

