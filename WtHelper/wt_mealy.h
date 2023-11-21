/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块实现了一种简单的有限状态机。工作流程如下：
 *	1、当前某个已定义的事件发生时，用户需要把事件和关联参数，调用函数wt_mealy_raise传递给状态机。
 *	2、状态机接收后会根据状态转换表进行状态转换并执行关联的动作。
 *	3、在执行状态转换时，如果当前状态关联的次态是最终状态，则状态机不再响应事件。
 *
 * 模块规格
 * 状态机数量：无限。
 * 状态容量：256条。
 * 事件容量：256条。
 * 转换表容量：65535条。
 *
 * 注意事项
 * 1、在多任务中函数mealy_raise是不安全的。
 * 2、模块并没有对函数参数作任何检测，需要留意。
 *
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/11/21   feallee@hotmail.com 删除动态内存的使用，以增加模块通用性；优化相关接口。
 * 2023/07/31   feallee@hotmail.com 初版.
 *
 */

#ifndef __WT_MEALY_H_
#define __WT_MEALY_H_
#include <stdint.h>
#include <stdbool.h>

 /// @brief 状态转换表控制块。
typedef struct
{
	/// @brief 获取或设置状态。
	char state;
	/// @brief 获取或设置事件。
	char event;
	/// @brief 获取或设置次状。
	char next;
	/// @brief 获取或设置动作。
	void (*action)(char from, char to, char event, void* parameter);
}wt_mealy_transition_type;

/// @brief 状态机控制块。
typedef struct
{
	/// @brief 获取或设置状态转换表指针。
	wt_mealy_transition_type* table;
	/// @brief 获取或设置状态转换表数量。
	uint16_t count;
	/// @brief 获取或设置起始状态。
	char final;
	/// @brief 获取或设置最终状态。
	char current;
}wt_mealy_machine_type;

/// @brief 初始化状态机。
/// @param table 状态转换表指针。
/// @param count 状态转换表数量。
/// @param initial 起始状态。
/// @param final 最张状态。
void wt_mealy_init(wt_mealy_machine_type* machine, wt_mealy_transition_type* table, uint16_t count, char initial, char final);

/// @brief 向状态机引发事件。
/// @param event 事件。
/// @param parameter 事件状态参数。
/// @return 返回状态机是否支持此事件。
bool wt_mealy_raise(wt_mealy_machine_type* machine, char event, void* parameter);

/// @brief 获取状态机当前状态。
/// @return 返回状态机当前状态。
char wt_mealy_getstate(wt_mealy_machine_type* machine);

/// @brief 获取状态机是否停机。
/// @return 返回状态机是否停机。
bool wt_mealy_isfinal(wt_mealy_machine_type* machine);

#endif // !__MEALY_H__

