/* MATHEW NG’ANG’A   I39/30422/2015
  SAMUEL KIMATHI     I39/36074/2013
  BENSON MWINGA      I39/2212/2013
  AMOS OMWOYO        I39/2294/2015

 * main.h
 */

#ifndef MAIN_H_
#define MAIN_H_
#include"MK60DZ10.h"
#include"gpio.h"
#include"uart.h"
#define BUTTON1 (1 << 19)

#define LED1    (1 << 11)
#define LED2    (1 << 28)
#define LED3    (1 << 29)


#define LED1_ON    GPIOA_PCOR = LED1
#define LED2_ON    GPIOA_PCOR = LED2
#define LED3_ON    GPIOA_PCOR = LED3


#define LED1_OFF   GPIOA_PSOR = LED1
#define LED2_OFF   GPIOA_PSOR = LED2
#define LED3_OFF   GPIOA_PSOR = LED3

#define LED1_TOGGLE GPIOA_PTOR = LED1
#define LED2_TOGGLE GPIOA_PTOR = LED2
#define LED3_TOGGLE GPIOA_PTOR = LED3


extern int periph_clk_khz;
void delay(void);
extern void SystemInit(void);
#endif /* MAIN_H_ */
