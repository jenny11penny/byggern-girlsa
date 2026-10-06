#ifndef CAN_H
#define CAN_H

#include <stdint.h>

void CAN_Init(void);
void CAN_SendMessage();
void CAN_Receive();



#endif