//
// Created by QHJSTC on 2021/1/16.
//
#include "Esp8266.h"
/****************************************************
 *
 * wifi ���ں���
 * ESP8266����
 *
******************************************************/
#define TransmitDelay 100

u8 Wifi_DataSta = 0;         //1 is the data ok, 0 is preparing
u8 Wifi_Buff[255] = {};
u8 Wifi_data[Wifi_Size] = {};
int Wifi_Index = 0;
void Wifi_Init(){
    __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);   //open the IDLE interrupt
    HAL_UART_Receive_DMA(&huart3, (u8*) Wifi_Buff, 255);
/************************************/
    Wifi_Send("AT\r\n");                                 //send the information to the wifi
    HAL_Delay(TransmitDelay);
    Wifi_Send("AT+GMR\r\n");
    HAL_Delay(TransmitDelay);
    Wifi_ClientConfigure();
}

void Wifi_Send(u8 *data){
    HAL_UART_Transmit(&huart3, (u8 *)data, strlen(data), 0xFFFF);
}

//Single connection client
void Wifi_ClientConfigure() {
    Wifi_Send("AT+CWMODE=1\r\n");
    HAL_Delay(TransmitDelay);
    Wifi_Send("AT+RST\r\n");
    HAL_Delay(4000);          //Wait 3 seconds RST to complete configuration
    Wifi_Send("AT+CWJAP=\"qhj\",\"12345678qhj\"\r\n");
    HAL_Delay(TransmitDelay);
    Wifi_Send("AT+CIPMUX=0\r\n");
    HAL_Delay(TransmitDelay);
    Wifi_Send("AT+CIPMODE=1\r\n");
    HAL_Delay(TransmitDelay);
    Wifi_Send("AT+CIPSEND\r\n");
}

//Analyse the Wifi_data
void Wifi_DataAnalysis(){
    if(Wifi_DataSta == 1) {
        printf("We have receive the wifi data\r\n");
        printf(Wifi_data);
        memset(Wifi_data, 0, Wifi_Size);         //wipe data;
    }
}