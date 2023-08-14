/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块实现了一种简单的有限状态机，非常适用于嵌入式应用。
 *
 * 模块规格
 * 状态机：无限（受内存资源限制）。
 * 状态容量：255条/状态机。
 * 事件容量：256条/状态。
 * 转换表：1张/状态机。
 * 转换表容量：65535条/转换表。
 * 停机：支持。
 * 共用转换表：支持。
 *
 * 注意事项
 * 1、为了避免内存泄漏，不再使用的状态机请调用函数wt_mealy_delete删除并释放状态机所占用资源。
 * 2、在多任务中函数mealy_raise是不安全的。
 *
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/07/31   feallee@hotmail.com 初版.
 *
 */

#ifndef __WT_MEALY_H_
#define __WT_MEALY_H_

 /// @brief 未知状态。注意：该状态不允许在状态转换表中使用。
#define WT_MEALY_STATE_UNKNOWN	(-1)

/// @brief 状态转换控制块。
typedef struct
{
	/// @brief 当前状态。不允许使用MEALY_STATE_UNKNOWN。
	char current;
	/// @brief 与当前状态关联事件。
	char event;
	/// @brief 与当前状态关联次态。不允许使用MEALY_STATE_UNKNOWN。
	char next;
	/// @brief 与当前状态关联动作，在转换状态后调用。注意：实现动作时不允许调用下列函数：mealy_raise。
	void(*action)(char from, char to, char event, size_t parameter);
} wt_mealy_transit_t;

/// @brief 状态机控制块。
typedef void* wt_mealy_t;

/// @brief 创建新的状态机。
/// @param transitTable 状态转换表。
/// @param transitCount 状态转换表数量。
/// @param initialState 起始状态。
/// @param finalState 最终状态。
/// @return 返回新创建的状态机。如果由于下列原因：
///		1、内存资源不足；
///		会导致创建失败，返回NULL。
wt_mealy_t wt_mealy_create(const wt_mealy_transit_t* transitTable, unsigned short transitCount, char initialState, char finalState);

/// @brief 向状态机引发事件并返回状态转换后的状态。
/// @param mealy 状态机。
/// @param event 事件。
/// @param parameter 事件关联参数。
/// @return 返回状态转换后的状态，可以与finalState比较，判断状态机是否进入了停机状态。如果返回MEALY_STATE_UNKNOWN表示当前状态不支持该事件。
char wt_mealy_raise(wt_mealy_t mealy, char event, size_t parameter);

/// @brief 获取状态机的当前状态。
/// @param 状态机。
/// @return 返回状态机的当前状态，可以与finalState比较，判断状态机是否进入了停机状态。
char wt_mealy_getcurrent(wt_mealy_t mealy);

/// @brief 删除并释放状态机所占用资源。
/// @param 状态机。
void wt_mealy_delete(wt_mealy_t mealy);
#endif // !__MEALY_H__

