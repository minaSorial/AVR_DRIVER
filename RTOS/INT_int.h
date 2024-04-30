/*
 * INT_int.h
 *
 *  Created on: 13 Nov 2023
 *      Author: Mizoo
 */


#ifndef INT_INT_H_
#define INT_INT_H_

#include "STD_BITMAN.h"
#include "avr/io.h"

#define INT_enterCritical() BIT_CLEAR(SREG,SREG_I)

#define INT_exitCritical() BIT_SET(SREG,SREG_I)

#endif /* INT_INT_H_ */
