/**
 ******************************************************************************
 * @file	can1_task.h
 * @author	Hampus Sandberg
 * @version	0.1
 * @date	2014-09-06
 * @brief
 ******************************************************************************
	Copyright (c) 2014 Hampus Sandberg.

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation, either
	version 3 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAN1_TASK_H_
#define CAN1_TASK_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"

/* Defines -------------------------------------------------------------------*/
/* Typedefs ------------------------------------------------------------------*/
typedef enum
{
	CAN1Connection_Connected,
	CAN1Connection_Disconnected,
} CAN1Connection;

typedef enum
{
	CAN1BitRate_10k,
	CAN1BitRate_20k,
	CAN1BitRate_50k,
	CAN1BitRate_125k,
	CAN1BitRate_250k,
	CAN1BitRate_500k,
	CAN1BitRate_800k,
	CAN1BitRate_1M,
	CAN1BitRate_Custom,
} CAN1BitRate;

typedef enum
{
	CAN1Termination_Connected,
	CAN1Termination_Disconnected,
} CAN1Termination;

typedef struct
{
	CAN1Connection connection;
	CAN1BitRate bitRate;
	CAN1Termination termination;
} CAN1Settings;

/* Function prototypes -------------------------------------------------------*/
void can1Task(void *pvParameters);
ErrorStatus can1SetTermination(CAN1Termination Termination);
ErrorStatus can1SetConnection(CAN1Connection Connection);
CAN1Settings can1GetSettings();
ErrorStatus can1SetSettings(CAN1Settings* Settings);


#endif /* CAN1_TASK_H_ */
