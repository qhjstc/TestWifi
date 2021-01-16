//
// Created by QHJSTC on 2021/1/16.
//

#ifndef TESTWIFI_ESP8266_H
#define TESTWIFI_ESP8266_H

#include "main.h"
#include "usart.h"
#include "string.h"

/*****外接设备********/

#define Wifi_Size 255


extern u8 Wifi_DataSta;
extern u8 Wifi_Buff[255];
extern u8 Wifi_data[Wifi_Size];
extern int Wifi_Index;

void Wifi_Init();
void Wifi_Send(u8 *data);
void Wifi_ClientConfigure();
void Wifi_DataAnalysis();

#endif //TESTWIFI_ESP8266_H
