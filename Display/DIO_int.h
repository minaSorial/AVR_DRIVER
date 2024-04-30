/*
 * DIO_int.h
 *
 *  Created on: 28 Jul 2023
 *      Author: Mizoo
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define  DIO_PORTA 0
#define  DIO_PORTB 1
#define  DIO_PORTC 2
#define  DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_INPUT 0
#define DIO_OUTPUT 1


#define DIO_LOW 0
#define DIO_HIGH 1

#define DIO_FLOATING 0
#define DIO_PULLUP 1
#define DIO_NOT_USED 0


typedef  struct{

 u8 u8PortIdx:2 ;
 u8 u8PinIdx: 4;
 u8 u8Direction :1;
 u8 u8InitValue:1;
 u8 u8InputMode:1;

}DIO_tstrPIN;

typedef struct{

	 u8 u8PortIdx;
	 u8 u8Mask;
	 u8 u8Direction;
	 u8 u8InitValue;
	 u8 u8InputMode;

}DIO_tstrPORT;


/*
Description:
	intilaize the DIO based on configuration.
return:NA
Input: NA
*/
void DIO_vidInit(void);

STD_tenuReturn DIO_enuSetPinValue(u8 u8PinIdxCpy,u8 u8ValueCpy);



/*
Input:
			u8PinIdxCpy: PIN index from the Configured PINS.
			pu8ValueCpy: pointer to read the value.
		Return: retutn execution State.
				STD_enuOK,
				STD_enuOutOfRange
				STD_enuNOK.
*/
STD_tenuReturn DIO_enuGetPinValue(u8 u8PinIdxCpy,u8 * pu8ValueCpy);

STD_tenuReturn DIO_enuSetPinDirection(u8 u8PinIdxCpy,u8 u8DirCpy);



STD_tenuReturn DIO_enuSetPortValue(u8 u8PortIdxCpy,u8 u8ValueCpy);

STD_tenuReturn DIO_enuGetPortValue(u8 u8PortIdxCpy,u8 * pu8ValueCpy);

STD_tenuReturn DIO_enuSetPortDirecrion(u8 u8PortIdxCpy,u8 u8DirCpy);

#endif /* DIO_INT_H_ */
