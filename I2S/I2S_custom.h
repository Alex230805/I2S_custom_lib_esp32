#ifndef I2S_CUSTOM_H
#define I2S_CUSTOM_H


#include <com.h>
#include <Arduino.h>

/*
 *
 *  Compilation flags:
 *
 *  I2S_FIFO_IMP -> provide the fifo interface
 *
 *  I2S_CONTROLLER_IMP -> provide the register configuration interface
 *
 *  I2S_DMA_IMP -> provide the interface for dma operation
 *
 *  I2S_PDM_IMP -> provide the interface for pulse intensity operation
 *
 *  I2S_INT_IMP -> provide the interface for interrupt operation
 *
 * */

#define I2S_FIFO_IMP
#define I2S_CONTROLLER_IMP
#define I2S_DMA_IMP
#define I2S_PDM_IMP
#define I2S_INT_IMP

/* address for each register */

/* Mask for register cluster  a and b */
#define I2S0_MASK 0x3FF4F000
#define I2S1_MASK 0x3FF6D000

/* read and write fifo register */
#define I2S0_FIFO_WR_REG (I2S0_MASK | 0x000)
#define I2S1_FIFO_WR_REG (I2S1_MASK | 0x000)
#define I2S0_FIFO_RD_REG (I2S0_MASK | 0x004)
#define I2S1_FIFO_RD_REG (I2S1_MASK | 0x004)

/* config register a and b */
#define I2S0_CONF_REG (I2S0_MASK | 0x008)
#define I2S0_CONF1_REG (I2S0_MASK | 0x0a0)
#define I2S0_CONF2_REG (I2S0_MASK | 0x0a8)
#define I2S0_TIMING_REG (I2S0_MASK | 0x01c)
#define I2S0_FIFO_CONF_REG (I2S0_MASK | 0x020)
#define I2S0_CONF_SINGLE_DATA_REG (I2S0_MASK | 0x028)
#define I2S0_CONF_CHAN_REG (I2S0_MASK | 0x02c)
#define I2S0_LC_HUNG_CONF_REG (I2S0_MASK | 0x074)
#define I2S0_CLKM_CONF_REG (I2S0_MASK | 0x0ac)
#define I2S0_SAMPLE_RATE_CONF_REG (I2S0_MASK | 0x0b0)
#define I2S0_PD_CONF_REG (I2S0_MASK | 0x0a4)
#define I2S0_STATE_REG (I2S0_MASK | 0x0bc)


#define I2S1_CONF_REG (I2S1_MASK | 0x08)
#define I2S1_CONF1_REG (I2S1_MASK | 0xa0)
#define I2S1_CONF2_REG (I2S1_MASK | 0xa8)
#define I2S1_TIMING_REG (I2S1_MASK | 0x1c)
#define I2S1_FIFO_CONF_REG (I2S1_MASK | 0x20)
#define I2S1_CONF_SINGLE_DATA_REG (I2S1_MASK | 0x28)
#define I2S1_CONF_CHAN_REG (I2S1_MASK | 0x2c)
#define I2S1_LC_HUNG_CONF_REG (I2S1_MASK | 0x74)
#define I2S1_CLKM_CONF_REG (I2S1_MASK | 0xac)
#define I2S1_SAMPLE_RATE_CONF_REG (I2S1_MASK | 0xb0)
#define I2S1_PD_CONF_REG (I2S1_MASK | 0xa4)
#define I2S1_STATE_REG (I2S1_MASK | 0xbc)


/* DMA register a and b */

#define I2S0_LC_CONF_REG (I2S0_MASK | 0x60)
#define I2S0_RXEOF_NUM_REG (I2S0_MASK | 0x24)
#define I2S0_OUT_LINK_REG (I2S0_MASK | 0x30)
#define I2S0_IN_LINK_REG (I2S0_MASK | 0x34)
#define I2S0_OUT_EOF_DES_ADDR_REG (I2S0_MASK | 0x38)
#define I2S0_IN_EOF_DES_ADDR_REG (I2S0_MASK | 0x3c)
#define I2S0_OUT_EOF_BFR_DES_ADDR_REG (I2S0_MASK | 0x40)
#define I2S0_INLINK_DSCR_REG (I2S0_MASK | 0x48)
#define I2S0_INLINK_DSCR_BF0_REG (I2S0_MASK | 0x4c)
#define I2S0_INLINK_DSCR_BF1_REG (I2S0_MASK | 0x50)
#define I2S0_OUTLINK_DSCR_REG (I2S0_MASK | 0x54)
#define I2S0_OUTLINK_DSCR_BF0_REG (I2S0_MASK | 0x58)
#define I2S0_OUTLINK_DSCR_BF1_REG (I2S0_MASK | 0x5c)
#define I2S0_LC_STATE0_REG (I2S0_MASK | 0x6c)
#define I2S0_LC_STATE1_REG (I2S0_MASK | 0x70)


#define I2S1_LC_CONF_REG (I2S1_MASK | 0x60)
#define I2S1_RXEOF_NUM_REG (I2S1_MASK | 0x24)
#define I2S1_OUT_LINK_REG (I2S1_MASK | 0x30)
#define I2S1_IN_LINK_REG (I2S1_MASK | 0x34)
#define I2S1_OUT_EOF_DES_ADDR_REG (I2S1_MASK | 0x38)
#define I2S1_IN_EOF_DES_ADDR_REG (I2S1_MASK | 0x3c)
#define I2S1_OUT_EOF_BFR_DES_ADDR_REG (I2S1_MASK | 0x40)
#define I2S1_INLINK_DSCR_REG (I2S1_MASK | 0x48)
#define I2S1_INLINK_DSCR_BF0_REG (I2S1_MASK | 0x4c)
#define I2S1_INLINK_DSCR_BF1_REG (I2S1_MASK | 0x50)
#define I2S1_OUTLINK_DSCR_REG (I2S1_MASK | 0x54)
#define I2S1_OUTLINK_DSCR_BF0_REG (I2S1_MASK | 0x58)
#define I2S1_OUTLINK_DSCR_BF1_REG (I2S1_MASK | 0x5c)
#define I2S1_LC_STATE0_REG (I2S1_MASK | 0x6c)
#define I2S1_LC_STATE1_REG (I2S1_MASK | 0x70)

/* Pulse Density register a and b */

#define I2S0_PDM_CONF_REG (I2S0_MASK | 0xb4)
#define I2S0_PDM_FREQ_CONF_REG (I2S0_MASK | 0xb8)

#define I2S1_PDM_CONF_REG (I2S1_MASK | 0xb4)
#define I2S1_PDM_FREQ_CONF_REG (I2S1_MASK | 0xb8)

/* Interrupt register a and b */

#define I2S0_INT_RAW_REG (I2S0_MASK | 0x0c)
#define I2S0_INT_ST_REG (I2S0_MASK | 0x10)
#define I2S0_INT_ENA_REG (I2S0_MASK | 0x14)
#define I2S0_INT_CLR_REG (I2S0_MASK | 0x18)

#define I2S1_INT_RAW_REG (I2S1_MASK | 0x0c)
#define I2S1_INT_ST_REG (I2S1_MASK | 0x10)
#define I2S1_INT_ENA_REG (I2S1_MASK | 0x14)
#define I2S1_INT_CLR_REG (I2S1_MASK | 0x18)

/* Library based on common.h to econfigure basic and advance I2S mode/configuration */

void I2S_create_config();
void I2S_flush_config();

/* Function to operate on the FIFO register for Read and Write */

#ifdef I2S_FIFO_IMP

void I2S_fifo_set(uint32_t write,int cluster);
uint32_t I2S_fifo_get(int cluster);

#endif
/* Function to operate on the Control register */

#ifdef I2S_CONTROLLER_IMP

void I2S_config_0_set(uint32_t config,int cluster);
void I2S_config_1_set(uint32_t config,int cluster);
void I2S_config_2_set(uint32_t config,int cluster);
void I2S_config_timing_set(uint32_t config,int cluster);
void I2S_config_fifo_set(uint32_t config,int cluster);
void I2S_config_single_data_set(uint32_t config,int cluster);
void I2S_config_channel_set(uint32_t config,int cluster);
void I2S_config_timeout_d_set(uint32_t config,int cluster);
void I2S_config_bitclock_set(uint32_t config,int cluster);
void I2S_config_sample_rate_set(uint32_t config,int cluster);
void I2S_config_powerdown_set(uint32_t config,int cluster);
uint32_t I2S_config_get_status(int cluster);

#endif
/* Function to operate on the DMA registe */

#ifdef I2S_DMA_IMP

void I2S_dma_config(uint32_t config,int cluster);
void I2S_dma_rvx_data_count(uint32_t config,int cluster);
void I2S_dma_link_reg(uint32_t write, uint32_t read,int cluster);

uint32_t I2S_dma_get_eof_descriptop_address_in(int cluster);
uint32_t I2S_dma_get_eof_descriptor_address_out(int cluster);
uint32_t I2S_dma_get_eof_buffer_address_out(int cluster);
uint32_t* I2S_dma_get_link_in_descriptor(int cluster);
uint32_t* I2S_dma_get_link_out_descriptor(int cluster);

uint32_t I2S_dma_get_rx_status(int cluster);
uint32_t I2S_dma_get_tx_status(int cluster);

#endif

/* Function to operate on the Pulse Intensity register */

#ifdef I2S_PDM_IMP

void I2S_pdm_config_set(uint32_t config,int cluster);
void I2S_pdm_freq_set(uint32_t config,int cluster);

#endif
/* Function to operate on the Interrupt register */

#ifdef I2S_INT_IMP

uint32_t I2S_interrupt_get_raw(int cluster);
uint32_t I2S_interrupt_get_msk_status(int cluster);
void I2S_interrupt_set_enable_bit(uint32_t command,int cluster);
void I2S_interrupt_clear(uint32_t command,int cluster);

#endif

#ifndef I2S_IMPLEMENTATION
#define I2S_IMPLEMENTATION
#endif


#endif
