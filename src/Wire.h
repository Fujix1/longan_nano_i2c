/*
  
  Simple Wire
  I2C for Longan Nano

  Note: Still no reading functionality.

*/
#include <gd32vf103.h>

class TwoWire
{
  public:
    void begin(void);
    void beginTransmission(uint8_t);
    void write(uint8_t);
    void write(const uint8_t *, size_t);
    void endTransmission(void);
};

extern TwoWire Wire;