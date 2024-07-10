/****************************************************************************************************************************
  basic_pwm.ino
  For RP2040 boards
  Written by Dr. Benjamin Bird

  A basic example to get you up and running.

  Library by Khoi Hoang https://github.com/khoih-prog/RP2040_PWM
  Licensed under MIT license

  The RP2040 PWM block has 8 identical slices. Each slice can drive two PWM output signals, or measure the frequency
  or duty cycle of an input signal. This gives a total of up to 16 controllable PWM outputs. All 30 GPIO pins can be driven
  by the PWM block
*****************************************************************************************************************************/
#define _PWM_LOGLEVEL_        3
#include "RP2040_PWM.h"
#include "myDWIN.h"

#define ADDRESS_A     "1010"
#define ADDRESS_B     "1020"
#define DGUS_BAUD     115200



//creates pwm instance
RP2040_PWM* PWM_Instance;

float frequency;
float dutyCycle;

#define pinToUse      25
DWIN hmi(DGUS_BAUD);

// Event Occurs when response comes from HMI
void onHMIEvent(String address, int lastByte, String message, String response){  
  DEBUG_UART.println("OnEvent : [ A : " + address + " | D : "+ String(lastByte, HEX)+ " | M : "+message+" | R : "+response+ " ]"); 
  if (address == "1002"){
  // Take your custom action call
  }
}

void setup()
{
  //assigns pin 25 (built in LED), with frequency of 20 KHz and a duty cycle of 0%
  //PWM_Instance = new RP2040_PWM(pinToUse, 20000, 0);
  

  DEBUG_UART.begin(115200);
  DEBUG_UART.println("DWIN HMI ~ Hello World");
  hmi.echoEnabled(false);
  hmi.hmiCallBack(onHMIEvent);
  hmi.setPage(1);
}

void loop()
{
  delay(500);
  DEBUG_UART.println("500 sec delay");
  // PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  // Listen HMI Events
  hmi.listen();
}
