#include <stm8l15x_conf.h>
class Gpio {

public:
      
  enum GpioModeType {           /* Possible mode types */
    OUTPUT,
    INPUT
  };

  enum GpioIOType {             /* Possible input or output types */    
    OPEN_DRAIN,
    PUSH_PULL,
    FLOAT,
    PULL_UP
  };

  enum GpioInterruptSpeedType { /* Possible interrupt(input) or speed(output) types */
    NO_INTERRUPT,
    SET_INTERRUPT,
    MHZ_2,
    MHZ_10
  };        
    
private:
    GPIO_TypeDef* port;
    GPIO_Pin_TypeDef pin;
    
public:
  
    Gpio(GPIO_TypeDef* Port,
         GPIO_Pin_TypeDef Pin,
         Gpio::GpioModeType Mode,
         Gpio::GpioIOType IOtype,
         Gpio::GpioInterruptSpeedType IStype);
  
    Gpio(GPIO_TypeDef* Port,
         GPIO_Pin_TypeDef Pin);
    ~Gpio();
    
    void Init( Gpio::GpioModeType Mode,
               Gpio::GpioIOType IOtype,
               Gpio::GpioInterruptSpeedType IStype);
    
    void set(void);
    void reset(void);
    void toogle(void);
    uint8_t readBit(void);
    
    void setPort(GPIO_TypeDef* Port);
    void setPin(GPIO_Pin_TypeDef Pin);
    void setMode(Gpio::GpioModeType Mode);
    void setIOtype(Gpio::GpioIOType IOtype);
    void setIStype(Gpio::GpioInterruptSpeedType IStype);
    
  };