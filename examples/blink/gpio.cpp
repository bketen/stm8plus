#include "gpio.h"

/* Constructor */
Gpio::Gpio(GPIO_TypeDef* Port,
                GPIO_Pin_TypeDef Pin,
                Gpio::GpioModeType Mode,
                Gpio::GpioIOType IOtype,
                Gpio::GpioInterruptSpeedType IStype): port(Port), pin(Pin)
{
  setMode(Mode);
  setIOtype(IOtype);
  setIStype(IStype);
}

/* Constructor */
Gpio::Gpio(GPIO_TypeDef* Port,
           GPIO_Pin_TypeDef Pin): port(Port), pin(Pin)
{
  setMode(Gpio::INPUT);
  setIOtype(Gpio::FLOAT);
  setIStype(Gpio::NO_INTERRUPT);
}

/* Destructor */
Gpio::~Gpio()
{
  /* load reset value */
  port->DDR &= (uint8_t)(~(pin));
  port->CR1 &= (uint8_t)(~(pin));
  port->CR2 &= (uint8_t)(~(pin));
}

/* Gpio Init */
void Gpio::Init( Gpio::GpioModeType Mode,
                 Gpio::GpioIOType IOtype,
                 Gpio::GpioInterruptSpeedType IStype)
{
  setMode(Mode);
  setIOtype(IOtype);
  setIStype(IStype);
}

/* Set the selected pin to HIGH */
void Gpio::set(void){
  port->ODR |= pin;
}

/* Set the selected pin to LOW */
void Gpio::reset(void){
  port->ODR &= (uint8_t)(~pin);
}

void Gpio::toogle(void){         
  port->ODR ^= pin;
}

uint8_t Gpio::readBit(void){         
  return (port->IDR & (uint8_t)pin);
}

void Gpio::setPort(GPIO_TypeDef* Port){
  port = Port;
}

void Gpio::setPin(GPIO_Pin_TypeDef Pin){
  pin = Pin;
}

void Gpio::setMode(Gpio::GpioModeType Mode){  
  if (Mode == OUTPUT) { port->DDR |= pin; }
  else if (Mode == INPUT) { port->DDR &= (uint8_t)(~(pin)); }
}

void Gpio::setIOtype(Gpio::GpioIOType IOtype){  
  if ((IOtype == FLOAT)|(IOtype == OPEN_DRAIN)) {port->CR1 &= (uint8_t)(~(pin));}
  else if ((IOtype == PULL_UP)|(IOtype == PUSH_PULL)) {port->CR1 |= pin;}
}

void Gpio::setIStype(Gpio::GpioInterruptSpeedType IStype){  
  if ((IStype == NO_INTERRUPT)|(IStype == MHZ_2)) {port->CR2 &= (uint8_t)(~(pin));}
  else if ((IStype == SET_INTERRUPT)|(IStype == MHZ_10)) {port->CR2 |= pin;}
}