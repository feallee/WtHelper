/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块使用数组实现的缓冲区，具有队列的FIFO功能。非常适用于嵌入式应用。
 *
 * 模块规格
 * 缓冲区容量：32768（受内存资源限制）。
 * 数据容量：1字节。
 *
 * 注意事项
 * 1、为了避免内存泄漏，不再使用的缓冲区请调用函数wt_buffer_delete删除并释放队列所占用资源。
 * 2、在多任务中函数wt_buffer_putchar和wt_buffer_getchar是不安全的。
 *
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com 初版.
 *
 */
#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_

 /// @brief 缓冲区控制块。
typedef void* wt_buffer_t;

/// @brief 缓冲区状态。
typedef enum
{
	/// @brief 缓冲区为空。
	WT_BUFFER_EMPTY,
	/// @brief 缓冲区已满。
	WT_BUFFER_FULL,
	/// @brief 缓冲区半满（既不为空，也不满）。
	WT_BUFFER_HALFFULL,
}wt_buffer_state;

/// @brief 创建一个缓冲区。
/// @param capacity 缓冲区容量，值域：[1,32768]。建议取4的倍数。
/// @return 返回创建的缓冲区。如果返回NULL，表示创建失败。
wt_buffer_t wt_buffer_create(unsigned short  capacity);

/// @brief 删除并释放缓冲区所占用的资源。
/// @param buffer 缓冲区。
void wt_buffer_delete(wt_buffer_t buffer);

/// @brief 获取缓冲区的状态。
/// @param buffer 缓冲区。
/// @return 返回缓冲区状态。
wt_buffer_state wt_buffer_getsatate(wt_buffer_t buffer);

/// @brief 将数据添加到缓冲区的结尾处。
/// @param buffer 缓冲区。
/// @param data 数据。
/// @return 返回向缓冲区添加数据的数量。
int wt_buffer_putchar(wt_buffer_t buffer, unsigned char data);

/// @brief 移除并返回位于缓冲区开始处的数据。
/// @param buffer 缓冲区。
/// @param data [out]数据。
/// @return 返回缓冲区开始处数据的数量。如果为0，表示缓冲区为空。
int wt_buffer_getchar(wt_buffer_t buffer, unsigned char* data);

/// @brief 清除缓冲区所有数据。
/// @param buffer 缓冲区。
void wt_buffer_clear(wt_buffer_t buffer);


#endif