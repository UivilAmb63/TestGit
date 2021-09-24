
#include <xc.h>
#include "Config.h"
#include <stdio.h>
#include <PIC16F628.h>


#define LEDSIGNAL RA1
#define RECEIVE_BUFFER_LENGHT 9
#define STATUS_VERSION_LENGHT 3
#define ERROR_MESSAGE_LENGTH 5
#define SEND_MESSAGE_BUFFER_LENGTH 64
#define GREEN_ALARM_DEVICE_0 RB4
#define YELLOW_ALARM_DEVICE_0 RB5
#define GREEN_ALARM_DEVICE_1 RB6
#define YELLOW_ALARM_DEVICE_1 RB7
#define GREEN_ALARM_DEVICE_2 RA6
#define YELLOW_ALARM_DEVICE_2 RA7
#define NUMBER_OF_DEVICES (3)

#define _XTAL_FREQ 4000000

void UART_Tx_Initialize(void){
    TXSTAbits.BRGH = 1;  // Set for high speed boud rate
    SPBRG = 25;  // Set the speed 9600
    
    TXSTAbits.SYNC = 0; // Set as asynchrounus mode
    RCSTAbits.SPEN = 1; // Serial port enable bit
    
    TRISBbits.TRISB2 = 0;  // Tx pin
    TRISBbits.TRISB1 = 1;  // Rx pin
}

int numberOfReadChars = 0;
int tryingToDetectCommunicationError = 0;
int numberOfCommunicationsErrorsDetected = 0;

//char RECEIVE_BUFFER_LENGTH;
//char buffer[ RECEIVE_BUFFER_LENGTH];


//const long int greenAlarmPins[NUMBER_OF_DEVICES] = { GREEN_ALARM_DEVICE_0, GREEN_ALARM_DEVICE_1, GREEN_ALARM_DEVICE_2 };
//const long int yellowAlarmPins[NUMBER_OF_DEVICES] = { YELLOW_ALARM_DEVICE_0, YELLOW_ALARM_DEVICE_1, YELLOW_ALARM_DEVICE_2 };

//enum DeviceLightStatus { UndefinedStatus = 0, OkStatus = 1, NotOkStatus = 2 };
//enum DeviceLightType { UndefinedType = 0, YellowType = 1, GreenType = 2 };

void main(void) {
    TRISA = 0x00;
}
