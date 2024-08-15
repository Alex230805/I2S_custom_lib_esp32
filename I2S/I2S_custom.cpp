#define I2S_IMPLEMENTATION


#include "I2S_custom.h"


void I2S_create_config(){
  config_create_config();
}
void I2S_flush_config(){
  config_upload();
}

/* Function to operate on the FIFO register for Read and Write */
#ifdef I2S_FIFO_IMP
void I2S_fifo_set(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_FIFO_WR_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_FIFO_WR_REG, write);
        break;
    default:
        break; 
  }
  return;
}
uint32_t I2S_fifo_get(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_FIFO_RD_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_FIFO_RD_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}
#endif
/* Function to operate on the Control register */

#ifdef I2S_CONTROLLER_IMP

void I2S_config_0_set(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CONF_REG, write);
        break;
    default:
        break;
  }
  return;
}

void I2S_config_1_set(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CONF1_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CONF1_REG, write);
        break;
    default:
      return;
  }
}

void I2S_config_2_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CONF2_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CONF2_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_timing_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_TIMING_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_TIMING_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_fifo_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_FIFO_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_FIFO_CONF_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_single_data_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CONF_SINGLE_DATA_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CONF_SINGLE_DATA_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_channel_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CONF_CHAN_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CONF_CHAN_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_timeout_d_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_LC_HUNG_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_LC_HUNG_CONF_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_bitclock_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_CLKM_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_CLKM_CONF_REG, write);
        break;
    default:
        break;
  }
    return;
}

void I2S_config_sample_rate_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_SAMPLE_RATE_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_SAMPLE_RATE_CONF_REG, write);
        break;
    default:
      return;
  }
}

void I2S_config_powerdown_set(uint32_t write,int cluster){
    switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_PD_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_PD_CONF_REG, write);
        break;
    default:
        break;
    }
    return;
}

uint32_t I2S_config_get_status(int cluster){
    uint32_t data = 0x00000000;
    switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_STATE_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_STATE_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

#endif

/* Function to operate on the DMA registe */

#ifdef I2S_DMA_IMP

void I2S_dma_config(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_LC_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_LC_CONF_REG, write);
        break;
    default:
        break;
  }
  return;
}

void I2S_dma_rvx_data_count(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_RXEOF_NUM_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_RXEOF_NUM_REG, write);
        break;
    default:
        break;
  }
  return;
}

void I2S_dma_link_reg(uint32_t write, uint32_t read,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_OUT_LINK_REG,write);
        config_add((uint32_t*)I2S0_IN_LINK_REG,read);
        break;
    case 1:
        config_add((uint32_t*)I2S1_OUT_LINK_REG,write);
        config_add((uint32_t*)I2S1_IN_LINK_REG,read);
        break;
    default:
        break;
  }
  return;
}


uint32_t I2S_dma_get_eof_descriptop_address_in(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_IN_EOF_DES_ADDR_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_IN_EOF_DES_ADDR_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;

}

uint32_t I2S_dma_get_eof_descriptor_address_out(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_OUT_EOF_DES_ADDR_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_OUT_EOF_DES_ADDR_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

uint32_t I2S_dma_get_eof_buffer_address_out(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_OUT_EOF_BFR_DES_ADDR_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_OUT_EOF_BFR_DES_ADDR_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

uint32_t* I2S_dma_get_link_in_descriptor(int cluster){
  uint32_t *data;
  data = (uint32_t*)malloc(sizeof(uint32_t)*3);
  switch(cluster){
    case 0:
        memcpy(&data[0],(uint32_t*)I2S0_INLINK_DSCR_REG, sizeof(uint32_t));
        memcpy(&data[1],(uint32_t*)I2S0_INLINK_DSCR_BF0_REG, sizeof(uint32_t));
        memcpy(&data[2],(uint32_t*)I2S0_INLINK_DSCR_BF1_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data[0],(uint32_t*)I2S1_INLINK_DSCR_REG, sizeof(uint32_t));
        memcpy(&data[1],(uint32_t*)I2S1_INLINK_DSCR_BF0_REG, sizeof(uint32_t));
        memcpy(&data[2],(uint32_t*)I2S1_INLINK_DSCR_BF1_REG, sizeof(uint32_t));    
        break;
    default:
        break;
  }
  return data;
}

uint32_t* I2S_dma_get_link_out_descriptor(int cluster){
  uint32_t *data;
  data = (uint32_t*)malloc(sizeof(uint32_t)*3);
  switch(cluster){
    case 0:
        memcpy(&data[0],(uint32_t*)I2S0_OUTLINK_DSCR_REG, sizeof(uint32_t));
        memcpy(&data[1],(uint32_t*)I2S0_OUTLINK_DSCR_BF0_REG, sizeof(uint32_t));
        memcpy(&data[2],(uint32_t*)I2S0_OUTLINK_DSCR_BF1_REG, sizeof(uint32_t)); 
        break;
    case 1:
        memcpy(&data[0],(uint32_t*)I2S1_OUTLINK_DSCR_REG, sizeof(uint32_t));
        memcpy(&data[1],(uint32_t*)I2S1_OUTLINK_DSCR_BF0_REG, sizeof(uint32_t));
        memcpy(&data[2],(uint32_t*)I2S1_OUTLINK_DSCR_BF1_REG, sizeof(uint32_t)); 
        break;
    default:
        break;
  }
  return data;
}

uint32_t I2S_dma_get_rx_status(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_LC_STATE0_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_LC_STATE0_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

uint32_t I2S_dma_get_tx_status(int cluster){
  uint32_t data = 0x00000000;
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_LC_STATE1_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_LC_STATE1_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

#endif

/* Function to operate on the Pulse Intensity register */

#ifdef I2S_PDM_IMP

void I2S_pdm_config_set(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_PDM_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_PDM_CONF_REG, write);
        break;
    default:
        break;
  }
  return;
}

void I2S_pdm_freq_set(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_PDM_FREQ_CONF_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_PDM_FREQ_CONF_REG, write);
        break;
    default:
        break;
  }
  return;
}

#endif

/* Function to operate on the Interrupt register */

#ifdef I2S_INT_IMP

uint32_t I2S_interrupt_get_raw(int cluster){
  uint32_t data = 0x00000000;  
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_INT_RAW_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_INT_RAW_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

uint32_t I2S_interrupt_get_msk_status(int cluster){
  uint32_t data = 0x00000000;  
  switch(cluster){
    case 0:
        memcpy(&data,(uint32_t*)I2S0_INT_ST_REG, sizeof(uint32_t));
        break;
    case 1:
        memcpy(&data,(uint32_t*)I2S1_INT_ST_REG, sizeof(uint32_t));
        break;
    default:
        break;
  }
  return data;
}

void I2S_interrupt_set_enable_bit(uint32_t write, int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_INT_ENA_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_INT_ENA_REG, write);
        break;
    default:
        break;
  }
  return;
}

void I2S_interrupt_clear(uint32_t write,int cluster){
  switch(cluster){
    case 0:
        config_add((uint32_t*)I2S0_INT_CLR_REG, write);
        break;
    case 1:
        config_add((uint32_t*)I2S1_INT_CLR_REG, write);
        break;
    default:
        break;
  }
  return;
}

#endif
