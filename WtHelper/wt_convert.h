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
#ifndef __WT_CONVERT_H_
#define __WT_CONVERT_H_
#include <stdint.h>

uint32_t wt_convert_scanformat(char* buffer, uint32_t count, const char* separator);


#endif