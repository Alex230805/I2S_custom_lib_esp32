#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <Arduino.h>


#define EMPTY_CONFIG_LIST 0x00

/* Upload flag status */

#define UPLOAD_MASK 0x10

#define UPLOAD_START_UPLOAD (UPLOAD_MASK | 0x01)
#define UPLOAD_CONFIG_BLOCK (UPLOAD_MASK | 0x02)
#define UPLOAD_CONFIG_LIST (UPLOAD_MASK | 0x03)
#define UPLOAD_END_UPLOAD (UPLOAD_MASK | 0x04)

/* Error flag status */

#define ERROR_MASK 0x20

#define ERROR_UPLOADING_BLOCK (ERROR_MASK | 0x01)
#define ERROR_UPLOADING_LIST (ERROR_MASK | 0x02)
#define ERROR_UPLOADING (ERROR_MASK | 0x03)

#define ERROR_GENERAL_ERROR (ERROR_MASK | 0x0f)



struct config_block{
  uint32_t *address;
  uint32_t value;
  struct config_block* next;
};

struct config_header{
  struct config_block* block_list;
  int block_conf_number;
  struct config_block* switch_header;
};


void config_create_config();
void config_add(uint32_t *address, uint32_t value);
void config_clear();
void __config_clear_rec();
uint32_t* config_get_by_address(uint32_t *address);
uint32_t* config_get_by_value(uint32_t value);

uint8_t config_upload();
uint8_t __config_upload_rec();

uint8_t config_test_upload();
uint8_t __config__test_upload_rec();

static struct config_header* I2C_config = NULL;

#endif
