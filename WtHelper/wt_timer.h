/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块使用单链表实现的软件定时器。非常适用于嵌入式应用。
 *
 * 模块规格
 * 定时器数量：无限（受内存资源限制）。
 * 工作模式：单次(默认)，重复。
 *
 * 注意事项
 * 1、为了避免内存泄漏，不再使用的软件定时器请调用函数wt_timer_delete删除并释放所占用资源。
 *
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com 初版.
 *
 */
#ifndef __WT_TIMER_H_

/// @brief 软件定时器控制块。
typedef void* wt_timer_t;

/// @brief 创建软件定时器。
/// @param interval 时间间隔。
/// @param 时间到达回调。
/// @return 返回创建的软件定时器。如果创建失败，返回NULL。
wt_timer_t wt_timer_create(unsigned int interval, void(*timed)(void));

/// @brief 更新所有软件定时器的时间。
void wt_timer_refresh(void);

/// @brief 执行所有软件定时器的时间达到回调函数。
void wt_timer_dowork(void);

/// @brief 复位软件定时器的时间。
/// @param timer 软件定时器。
void wt_timer_reset(wt_timer_t timer);

/// @brief 删除并释放所占用资源。
void wt_timer_delete(wt_timer_t timer);
#endif // !__WT_TIMER_H_
