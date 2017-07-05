/*MATHEW NG’ANG’A  I39/30422/2015
SAMUEL KIMATHI     I39/36074/2013
BENSON MWINGA      I39/2212/2013
AMOS OMWOYO        I39/2294/2015
*/
#include "main.h"
 void gpioa_init(void);

/* we configured button SW1  to toggle LED1,LED2,LED3 (ISR) */
int main(void)
{
  SystemInit();

  NVICICPR2 |= 1 << (87 & 0x1F);
  NVICISER2 |= 1 << (87 & 0x1F);

  gpioa_init();

  LED1_OFF;
  LED2_OFF;
  LED3_OFF;

}

/*brief  Button and LED initialization*/
void gpioa_init(void)
{
  PORTA_PCR19 = PORT_PCR_MUX(1) | PORT_PCR_IRQC(0xA) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
  PORTA_PCR11 = (PORT_PCR_MUX(1));
  PORTA_PCR28 = (PORT_PCR_MUX(1));
  PORTA_PCR29 = (PORT_PCR_MUX(1));

  GPIOA_PDDR = (LED1|LED2|LED3);
}

/* brief  Port A ISR Handler */
void PORTA_IRQHandler(void)
{
  PORTA_ISFR = 0xFFFFFFFF;
  LED1_TOGGLE;
  LED2_TOGGLE;
  LED3_TOGGLE;
}

