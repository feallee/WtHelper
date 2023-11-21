/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块是数据检验函数集合。
 *
 * 模块规格
 * 
 *
 * 注意事项
 * 
 *
 * 修订日志
 * 日期         作者                内容
 * ------------------------------------------------------------------------- 
 * 2023/11/21   feallee@hotmail.com 初版.
 */
#ifndef __WT_CHECK_H_
#define __WT_CHECK_H_
#include <stdint.h>

uint8_t wt_check_cs8(const uint8_t* buffer, uint32_t count);
uint16_t wt_check_cs16(const uint8_t* buffer, uint32_t count);
uint32_t wt_check_cs32(const uint8_t* buffer, uint32_t count);

uint8_t wt_check_bcc(const uint8_t* buffer, uint32_t count);




#endif