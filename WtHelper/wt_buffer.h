/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块使用数组实现的缓冲区，具有队列的 FIFO 功能。
 *
 * 模块规格
 * 缓冲区容量：最多 32768 字节。
 *
 * 注意事项
 * 1、在多任务中函数 wt_buffer_putchar 和 wt_buffer_getchar 是不安全的。
 * 2、模块并没有对函数参数作检测，需要留意。
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/11/21   feallee@hotmail.com 删除动态内存的使用，以增加模块通用性；优化相关接口。
 * 2023/08/08   feallee@hotmail.com 初版.
 */
#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_
#include <stdint.h>

 /// @brief 缓冲区控制块。
typedef struct
{
	/// @brief 获取或设置缓冲区关联的内存池。
	uint8_t* pool;
	/// @brief 获取或设置缓冲区的容量。
	int32_t capacity;
	/// @brief 获取或设置缓冲区读操作反转标志。
	uint16_t read_mirror : 1;
	/// @brief 获取或设置缓冲区读操作指针。
	uint16_t read_index : 15;
	/// @brief 获取或设置缓冲区写操作反转标志。
	uint16_t write_mirror : 1;
	/// @brief 获取或设置缓冲区写操作指针。
	uint16_t write_index : 15;
}wt_buffer_type;

/// @brief 初始化缓冲区。
/// @param buffer 缓冲区控制块。
/// @param pool 内存池。
/// @param capacity 缓冲区容量，最多 32768 字节。
void wt_buffer_init(wt_buffer_type* buffer, uint8_t* pool, int32_t capacity);

/// @brief 向缓冲区写入一个字节数据。
/// @param buffer 缓冲区控制块。
/// @param segment 源数据指针。
/// @return 返回成功写入缓冲区的数量。
int32_t wt_buffer_write_byte(wt_buffer_type* buffer, const uint8_t segment);

/// @brief 从缓冲区读取一个字节数据。
/// @param buffer 缓冲区控制块。
/// @param segment 目的数据指针。
/// @return 返回成功读取的数量。
int32_t wt_buffer_read_byte(wt_buffer_type* buffer, uint8_t* segment);

#endif