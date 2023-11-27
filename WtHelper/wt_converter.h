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
#ifndef __WT_CONVERTER_H_
#define __WT_CONVERTER_H_
#include <stdint.h>
 /// @brief 格式化字符串以支持函数 sscanf 解析。注意：
 /// @brief  1、缓冲区 buffer 需预留足够的空间避免溢出，因为连续两个分隔符之间会插入一个字符0x7F。
 /// @param buffer 字符串缓冲区。
 /// @param count 字符串数量。
 /// @param separator 分隔符。
 /// @return 返回格式化后的字符串数量。
uint32_t wt_converter_scanformat(char* buffer, uint32_t count, const char* separator);

/// @brief 将十六进制字符转换为十进制数。
uint8_t wt_converter_h2d(uint8_t value);

/// @brief 将十进制数转换为十六进制字符。
uint8_t wt_converter_d2h(uint8_t value);

/// @brief 将十六进制字符串转换为十进制数组。
uint32_t wt_converter_hs2b(uint8_t* buffer, uint32_t count);

/// @brief 将十进制数组转换为十六进制字符串。注意：
/// @brief  1、缓冲区 buffer 需预留两倍的空间，因为一个字节的数据需要用两个字节表示。
uint32_t wt_converter_b2hs(uint8_t* buffer, uint32_t count);
#endif