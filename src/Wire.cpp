/*
  
  Simple Wire
  I2C for Longan Nano

  Note: Still no reading functionality.

*/

#include "Wire.h"

void TwoWire::begin(void)
{
  // PB6: SCL
  // PB7: SDA
  rcu_periph_clock_enable(RCU_GPIOB);
  gpio_init(GPIOB, GPIO_MODE_AF_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_6 | GPIO_PIN_7);

  rcu_periph_clock_enable(RCU_I2C0);
  I2C_CTL1(I2C0) |= 54;  // 54MHz clock input
  I2C_CKCFG(I2C0) = 270; // divided into 100kHz
  I2C_CTL0(I2C0) |= I2C_CTL0_I2CEN;
}

void TwoWire::beginTransmission(uint8_t address)
{
  address = address << 1;

  I2C_CTL0(I2C0) |= I2C_CTL0_START;
  while (!(I2C_STAT0(I2C0) & I2C_STAT0_SBSEND));

  I2C_DATA(I2C0) = address;
  while (!(I2C_STAT0(I2C0) & I2C_STAT0_ADDSEND));
  const volatile uint16_t stat = I2C_STAT1(I2C0);
  (void)stat;
}

void TwoWire::write(uint8_t dat)
{
  I2C_DATA(I2C0) = dat;
  while (!(I2C_STAT0(I2C0) & I2C_STAT0_TBE));
}

void TwoWire::write(const uint8_t *dat, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    I2C_DATA(I2C0) = dat[i];
    while (!(I2C_STAT0(I2C0) & I2C_STAT0_TBE));
  }
}

void TwoWire::endTransmission(void)
{
  while (!(I2C_STAT0(I2C0) & I2C_STAT0_BTC));
  I2C_CTL0(I2C0) |= I2C_CTL0_STOP;
  while (I2C_STAT0(I2C0) & I2C_STAT0_BTC);
  while (I2C_CTL0(I2C0) & I2C_CTL0_STOP);
}

TwoWire Wire;
