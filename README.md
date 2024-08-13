# I2C advanced library for ESP32


This i2c library is specifically designed to control the more advanced i2s controller ( cluster A and B ) to simply use it.

All value for all register can be recovered from the official esp32 specs PFD in the i2s controller registers section, wich include for each register his unique settable value.

This library support dynamic compilation flag, to cut of from compilation part of code that for a specific operation are just unused.

### The main flag to activate are the following:

#define I2S_FIFO_IMP

#define I2S_CONTROLLER_IMP

#define I2S_DMA_IMP

#define I2S_PDM_IMP

#define I2S_INT_IMP

### A more specific description of each flag and what it does can be find in the top header of the I2S_custom library.
