//
// Created by QHJSTC on 2021/1/16.
//

#ifndef TESTWIFI_ESP8266_H
#define TESTWIFI_ESP8266_H

#include "main.h"
#include "usart.h"
#include "string.h"

#define Wifi_Size 200

extern u8 Wifi_Buff[1];
extern u8 Wifi_data[Wifi_Size];
extern int Wifi_Index;

void Wifi_Init();
void Wifi_Send(u8 *data);

#endif //TESTWIFI_ESP8266_H
