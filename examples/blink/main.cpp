#include <stm8l15x_conf.h>
#include <gpio.h>

Gpio green(GPIOE, GPIO_Pin_7, Gpio::OUTPUT, Gpio::PUSH_PULL, Gpio::MHZ_10);
Gpio blue(GPIOC, GPIO_Pin_7, Gpio::OUTPUT, Gpio::PUSH_PULL, Gpio::MHZ_10);

void InitClock(void)
{
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
  while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSI)
  {}
}

void _delay(void)
{
  unsigned long int j=150000;
  while(j--);
}

int main()
{
  InitClock();

  green.set();
  blue.reset();
  while(1)
  {
    _delay();
    green.toogle();
    blue.toogle();
    
  }
}
