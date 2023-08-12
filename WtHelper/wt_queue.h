/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块使用单链表实现了FIFO队列。非常适用于嵌入式应用。
 *
 * 模块规格
 * 队列容量：无限（受内存资源限制）。
 * 数据容量：CPU字长。
 *
 * 注意事项
 * 1、为了避免内存泄漏，不再使用的队列请调用函数wt_queue_delete删除并释放队列所占用资源。
 * 2、在多任务中函数wt_queue_enqueue和wt_queue_dequeue是不安全的。
 *
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com 初版.
 *
 */
#ifndef __WT_QUEUE_H_
#define __WT_QUEUE_H_

 /// @brief 队列控制块。
typedef void* wt_queue_t;

/// @brief 创建一个队列。
/// @return 返回创建的队列。如果返回NULL，表示创建失败。
wt_queue_t wt_queue_create(void);

/// @brief 将数据添加到队列的结尾处。
/// @param queue 队列。
/// @param data 数据。
/// @return 返回向队列添加数据的数量。
int wt_queue_enqueue(wt_queue_t queue, size_t data);

/// @brief 移除并返回位于队列开始处的数据。
/// @param queue 队列。
/// @param data 数据。
/// @return 返回队列开始处数据的数量。如果为0，表示队列为空。
int wt_queue_dequeue(wt_queue_t queue, size_t* data);

/// @brief 返回位于队列开始处的数据但不将其移除。
/// @param queue 队列。
/// @param data 数据。
/// @return 返回队列开始处数据的数量。如果为0，表示队列为空。
int wt_queue_peek(wt_queue_t queue, size_t* data);

/// @brief 删除并释放队列所占用的资源。
/// @param queue 队列。
void wt_queue_delete(wt_queue_t queue);

#endif