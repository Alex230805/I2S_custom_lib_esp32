# I2C advanced library for ESP32


This i2c library is specifically designed to control the more advanced i2s controller ( cluster A and B ) to simply use it.

All value for all register can be recovered from the official esp32 specs PFD in the i2s controller registers section, wich include for each register his unique settable value.

This library support dynamic compilation flag, to cut of from compilation part of code that for a specific operation are just unused.


#### ==================================================

### The main flag to activate are the following:

- #define I2S_FIFO_IMP

- #define I2S_CONTROLLER_IMP

- #define I2S_DMA_IMP

- #define I2S_PDM_IMP

- #define I2S_INT_IMP

### A more specific description of each flag and what it does can be find in the top header of the I2S_custom library.


#### ==================================================


## How to use the library

After the library has been included in the main project file it's possible to start the compilation. To optimize the file size compilation it's possible to exclude 
some part of the code by just decomment one or may of the 5 compilation flags that can be founded on top of the header file of the I2C library, 

To <strong>Start</strong> use the library you first need to add on top of all the project a call to the <strong>"I2S_create_config()"</strong> function, to setting up properly 
the library and the static variable.

After that you can start to use the library, call any of the register-dedicated functions to set up you desired configuration for the I2S interface. 

To upload the configuration you need to flush it, so you need to call the <strong>"I2S_flush_config()"</strong> only <strong>AFTER</strong> all registers are setted up correctly.

For every register-dedicated function you need to specify the cluster of I2S interface to use, so registers section A or registers section B.

After that the content of the register can be written by insert in the <strong>"write"</strong> variable in a function an uint32_t formatted bytes with the desired content

#### !!: You can set up your project like you want, BUT you have to consider WHERE and WHEN put the "I2S_create_config()" and the "I2S_flush_config()" function.


Now you can enjoy work with this hight speed interface :)


#### ==================================================

## List of function:


#### Main function

- void I2S_create_config();
- void I2S_flush_config();

#### I2S_FIFO_IMP

- void I2S_fifo_set(uint32_t write,int cluster);
- uint32_t I2S_fifo_get(int cluster);

#### I2S_CONTROLLER_IMP

- void I2S_config_0_set(uint32_t config,int cluster);
- void I2S_config_1_set(uint32_t config,int cluster);
- void I2S_config_2_set(uint32_t config,int cluster);
- void I2S_config_timing_set(uint32_t config,int cluster);
- void I2S_config_fifo_set(uint32_t config,int cluster);
- void I2S_config_single_data_set(uint32_t config,int cluster);
- void I2S_config_channel_set(uint32_t config,int cluster);
- void I2S_config_timeout_d_set(uint32_t config,int cluster);
- void I2S_config_bitclock_set(uint32_t config,int cluster);
- void I2S_config_sample_rate_set(uint32_t config,int cluster);
- void I2S_config_powerdown_set(uint32_t config,int cluster);
- uint32_t I2S_config_get_status(int cluster);

#### I2S_DMA_IMP

- void I2S_dma_config(uint32_t config,int cluster);
- void I2S_dma_rvx_data_count(uint32_t config,int cluster);
- void I2S_dma_link_reg(uint32_t write, uint32_t read,int cluster);
- uint32_t I2S_dma_get_eof_descriptop_address_in(int cluster);
- uint32_t I2S_dma_get_eof_descriptor_address_out(int cluster);
- uint32_t I2S_dma_get_eof_buffer_address_out(int cluster);
- uint32_t* I2S_dma_get_link_in_descriptor(int cluster);
- uint32_t* I2S_dma_get_link_out_descriptor(int cluster);
- uint32_t I2S_dma_get_rx_status(int cluster);
- uint32_t I2S_dma_get_tx_status(int cluster);

#### I2S_PDM_IMP

- void I2S_pdm_config_set(uint32_t config,int cluster);
- void I2S_pdm_freq_set(uint32_t config,int cluster);

#### I2S_INT_IMP

- uint32_t I2S_interrupt_get_raw(int cluster);
- uint32_t I2S_interrupt_get_msk_status(int cluster);
- void I2S_interrupt_set_enable_bit(uint32_t command,int cluster);
- void I2S_interrupt_clear(uint32_t command,int cluster);
