/*
  
  Simple Wire
  I2C lib for Longan Nano

  Based on https://github.com/riscv-mcu/GD32VF103_Firmware_Library/blob/master/Examples/I2C/Master_transmitter/main.c
  Note: Still no reading functionality.

*/

#include <gd32vf103.h>

class TwoWire
{
  public:
    void begin(void);
    void beginTransmission(uint8_t);
    size_t write(uint8_t);
    size_t write(const uint8_t *, size_t);
    void endTransmission(void);
};

extern TwoWire Wire;