#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

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
  uint32_t address;
  uint32_t value;
  struct config_block* next;
};

struct config_header{
  struct config_block* block_list;
  int block_conf_number;
  struct config_block* switch_header;
};


extern void config_create_config();
extern void config_add(uint32_t address, uint32_t value);
extern void config_clear();
extern void __config_clear_rec();
extern struct config_block* config_get_by_address(uint32_t address);
extern struct config_block* config_get_by_value(uint32_t value);

extern uint8_t config_upload();
extern uint8_t __config_upload_rec();

extern uint8_t config_test_upload();
extern uint8_t __config__test_upload_rec();

extern struct config_header* I2C_config;

#ifndef COMMON_IMPLEMENTATION
#define COMMON_IMPLEMENTATION
#endif

#endif
