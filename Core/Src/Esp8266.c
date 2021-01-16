//
// Created by QHJSTC on 2021/1/16.
//
#include "Esp8266.h"
/****************************************************
 *
 * wifi ´®¿Úº¯Êý
 * ESP8266µ÷ÊÔ
 *
******************************************************/
u8 Wifi_Buff[1] = {};
u8 Wifi_data[Wifi_Size] = {};
int Wifi_Index = 0;
void Wifi_Init(){
    __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);   //open the IDLE interrupt
    HAL_UART_Receive_DMA(&huart3, (u8*) Wifi_Buff, 1);
/************************************/
    Wifi_Send("AT\r\n");                                 //send the information to the wifi
    HAL_Delay(10);
    Wifi_Send("AT+GMR\r\n");
    HAL_Delay(10);
    Wifi_Send()
}

void Wifi_Send(u8 *data){
    HAL_UART_Transmit(&huart3, (u8 *)data, strlen(data), 0xFFFF);
}

void Wifi_Check(){
}