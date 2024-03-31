/*
 * OS_priv.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Mahmoud_Ali
 */

#ifndef OS_PRIV_H_
#define OS_PRIV_H_

typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
}Task_t;

static void voidScheduler(void);

#endif /* OS_PRIV_H_ */
