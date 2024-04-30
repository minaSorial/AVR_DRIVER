/*
 * SEG_int.h
 *
 *  Created on: 8 Aug 2023
 *      Author: Mizoo
 */

#ifndef SEG_INT_H_
#define SEG_INT_H_




#define SEG_LOW 0
#define SEG_HIGH 1

#define SEG_COM_ANODE  0 // active low
#define SEG_COM_CATHOD 1 //  active hig


#define SEG_ENABLED 1
#define SEG_DISABLED 0






typedef  struct{

 u8 u8PortIdx ;
 u8 u8ControlPinIdx;

 u8 u8InitValue;
 u8 u8Type :1;
 u8 u8InitState:1;
}SEG_tstr;



/*
Description:
	intilaize the SEG based on configuration.
return:NA
Input: NA
*/
void SEG_vidInit(void);

STD_tenuReturn SEG_enuEnable(u8 u8SegmentIdx);

STD_tenuReturn SEG_enuDisable(u8 u8SegmentIdx);

STD_tenuReturn SEG_enuWrite (u8 u8SegmentIdx,u8 u8Number);






#endif /* SEG_INT_H_ */
