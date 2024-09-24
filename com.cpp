#define COMMON_IMPLEMENTATION

#include "com.h"



void config_create_config(){
  I2C_config = (struct config_header*)malloc(sizeof(struct config_header));
  I2C_config->block_list = NULL;
  I2C_config->block_conf_number = 0;
  I2C_config->switch_header = NULL;
  return;
}

void config_clear(){
  uint32_t* address;
  if(I2C_config->block_conf_number == 0){
    I2C_config->switch_header = NULL;
    return;
  }
  if(I2C_config->switch_header != NULL){
    address = (uint32_t*)I2C_config->switch_header;
    I2C_config->switch_header = I2C_config->switch_header->next;
    config_clear();
  }else{
    return;
  }
  free(address);
  address = NULL;
  I2C_config->block_conf_number -= 1;
  return;

}


void config_add(uint32_t *address, uint32_t value){
  struct config_block* conf = NULL;
  conf = (struct config_block*)malloc(sizeof(struct config_block));
  conf->address = address;
  conf->value = value;
  conf->next = NULL;
  if(I2C_config->block_conf_number == 0){
    I2C_config->block_list = conf;
  }else{
    I2C_config->switch_header = I2C_config->block_list;
    while(I2C_config->switch_header->next != NULL){
      I2C_config->switch_header = I2C_config->switch_header->next;
    }
    I2C_config->switch_header->next = conf;
    I2C_config->switch_header = NULL;
  }
  I2C_config->block_conf_number += 1;
  return;
}

uint32_t* config_get_by_address(uint32_t *address){
  uint32_t *adr = NULL;
  I2C_config->switch_header = I2C_config->block_list;
  while(I2C_config->switch_header->next != NULL && I2C_config->switch_header->next->address != address){
      I2C_config->switch_header = I2C_config->switch_header->next;
  }
  if(I2C_config->switch_header != NULL){
    adr = (uint32_t*)I2C_config->switch_header;
  }
  I2C_config->switch_header = NULL;
  return adr;
}
uint32_t* config_get_by_value(uint32_t value){
  uint32_t *adr = NULL;
  I2C_config->switch_header = I2C_config->block_list;
  while(I2C_config->switch_header->next != NULL && I2C_config->switch_header->next->value != value){
      I2C_config->switch_header = I2C_config->switch_header->next;
  }
  if(I2C_config->switch_header != NULL){
    adr = (uint32_t*)I2C_config->switch_header;
  }
  I2C_config->switch_header = NULL;
  return adr;
}

void config_upload(){
  if(I2C_config->block_conf_number == 0) return;
  I2C_config->switch_header = I2C_config->block_list;

  while(I2C_config->switch_header->next != NULL){
    memcpy(I2C_config->switch_header->address,&I2C_config->switch_header->value,sizeof(uint32_t));
    I2C_config->switch_header = I2C_config->switch_header->next;
  }
  memcpy(I2C_config->switch_header->address,&I2C_config->switch_header->value,sizeof(uint32_t));
  I2C_config->switch_header = NULL;
  return;
}
