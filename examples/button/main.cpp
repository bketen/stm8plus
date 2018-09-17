#include <stm8l15x_conf.h>
#include <gpio.h>

Gpio green(GPIOE, GPIO_Pin_7, Gpio::OUTPUT, Gpio::PUSH_PULL, Gpio::MHZ_10);
Gpio blue(GPIOC, GPIO_Pin_7);
Gpio buton(GPIOC, GPIO_Pin_1, Gpio::INPUT, Gpio::FLOAT, Gpio::NO_INTERRUPT);

void InitClock(void)
{
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
  while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSI)
  {}
}

int main()
{
  InitClock();
  blue.Init( Gpio::OUTPUT, Gpio::PUSH_PULL, Gpio::MHZ_10);

  while(1)
  {
    if (buton.readBit()) {
      green.set();
      blue.reset();
    }
    else
    {
      green.reset();
      blue.set();
    }
  }
}
