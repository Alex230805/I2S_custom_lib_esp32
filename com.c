#define COMMON_IMPLEMENTATION

#include "./com.h"



extern void create_config(){
  I2C_config = (struct config_header*)malloc(sizeof(struct config_header));
  I2C_config->block_list = NULL;
  I2C_config->block_conf_number = 0;
  I2C_config->switch_header = NULL;
  return;
}

extern void config_clear(){
  uint32_t* address;
  if(I2C_config->block_conf_number == 0){
    I2C_config->switch_header = NULL;
    return;
  }
  if(I2C_config->switch_header->next != NULL){
    I2C_config->switch_header = I2C_config->switch_header->next;
    address = I2C_config->switch_header->next;
    config_clear();
  }
  free(address);
  address = NULL;
  I2C_config->block_conf_number -= 1;
  return;

}


extern void __config_clear_rec(){
  I2C_config->switch_header = I2C_config->block_list;
  config_clear();
}

extern void config_add(uint32_t address, uint32_t value){
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

extern struct config_block* config_get_by_address(uint32_t address){
  uint32_t adr = NULL;
  I2C_config->switch_header = I2C_config->block_list;
  while(I2C_config->switch_header->next != NULL && I2C_config->switch_header->next->address != address){
      I2C_config->switch_header = I2C_config->switch_header->next;
  }
  if(I2C_config->switch_header != NULL){
    adr = I2C_config->switch_header;
  }
  I2C_config->switch_header = NULL;
  return adr;
}
extern struct config_block* config_get_by_value(uint32_t value){
  uint32_t adr = NULL;
  I2C_config->switch_header = I2C_config->block_list;
  while(I2C_config->switch_header->next != NULL && I2C_config->switch_header->next->value != value){
      I2C_config->switch_header = I2C_config->switch_header->next;
  }
  if(I2C_config->switch_header != NULL){
    adr = I2C_config->switch_header;
  }
  I2C_config->switch_header = NULL;
  return adr;
}

extern uint8_t config_upload(){
  uint8_t status = NULL;
  if(I2C_config->block_conf_number == 0) return EMPTY_CONFIG_LIST;
  I2C_config->switch_header = I2C_config->block_list;
  status = __config_upload_rec();
  switch(status){
    case UPLOAD_CONFIG_BLOCK:
      return UPLOAD_CONFIG_LIST;
    default:
      return status;
  }
  return NULL;
}

extern uint8_t __config_upload_rec(){
  struct config_block* address = NULL;
  uint8_t status = UPLOAD_START_UPLOAD;

  if(I2C_config->switch_header->next != NULL){
    I2C_config->switch_header = I2C_config->switch_header->next;
    address = I2C_config->switch_header->next;
    status = __config_upload_rec();
  }
  switch(status){
    case ERROR_GENERAL_ERROR:
      return ERROR_GENERAL_ERROR;

    case ERROR_UPLOADING_BLOCK: 
      return ERROR_UPLOADING_LIST;

    case ERROR_UPLOADING_LIST:
      return ERROR_UPLOADING_LIST;

    case UPLOAD_CONFIG_BLOCK:
      break;

    default:
      return ERROR_GENERAL_ERROR;
  }
  if(address == NULL){
    return ERROR_UPLOADING_BLOCK;
  }
  memcpy(address->address,address->value,sizeof(address->value));
  return UPLOAD_CONFIG_BLOCK;
}




uint8_t config_test_upload(){
  uint8_t status = NULL;
  if(I2C_config->block_conf_number == 0) return EMPTY_CONFIG_LIST;
  I2C_config->switch_header = I2C_config->block_list;
  status = __config_upload_rec();
  switch(status){
    case UPLOAD_CONFIG_BLOCK:
      return UPLOAD_CONFIG_LIST;
    default:
      return status;
  }
  return NULL;
}

uint8_t __config_test_upload_rec(){
  struct config_block* address = NULL;
  uint8_t status = UPLOAD_START_UPLOAD;

  if(I2C_config->switch_header->next != NULL){
    I2C_config->switch_header = I2C_config->switch_header->next;
    address = I2C_config->switch_header->next;
    status = __config_upload_rec();
  }
  switch(status){
    case ERROR_GENERAL_ERROR:
      return ERROR_GENERAL_ERROR;

    case ERROR_UPLOADING_BLOCK: 
      return ERROR_UPLOADING_LIST;

    case ERROR_UPLOADING_LIST:
      return ERROR_UPLOADING_LIST;

    case UPLOAD_CONFIG_BLOCK:
      break;

    default:
      return ERROR_GENERAL_ERROR;
  }
  if(address == NULL){
    return ERROR_UPLOADING_BLOCK;
  }
  //Serial.println("Address: %d; Value: %d", address->address,address->value);
  return UPLOAD_CONFIG_BLOCK;
}
