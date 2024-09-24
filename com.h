#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <Arduino.h>


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
uint32_t* config_get_by_address(uint32_t *address);
uint32_t* config_get_by_value(uint32_t value);
void config_upload();

static struct config_header* I2C_config = NULL;

#endif
