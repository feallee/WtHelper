/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块实现了一种简单的有限状态机，非常适用于嵌入式应用。工作流程如下：
 *	1、当前某个已定义的事件发生时，用户需要把事件和关联参数，调用函数wt_mealy_raise传递给状态机。
 *	2、状态机接收后会根据状态转换表进行状态转换并执行关联的动作。
 *	3、在执行状态转换时，如果当前状态关联的次态是最终状态，则状态机不再响应事件。
 *
 * 模块规格
 * 状态机数量：无限（受内存资源限制）。
 * 状态容量：255条/状态机。
 * 事件容量：256条/状态。
 * 转换表：1张/状态机。
 * 转换表容量：65535条/转换表。
 * 共用转换表：支持。
 * 切换转换表：支持。
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

 /// @brief 未知状态。注意：该状态禁止在状态转换表中使用。
#define WT_MEALY_STATE_UNKNOWN	(-1)

/// @brief 状态转换控制块。
typedef struct
{
	/// @brief 当前状态。禁止使用MEALY_STATE_UNKNOWN。
	char current;
	/// @brief 与当前状态关联事件。
	char event;
	/// @brief 与当前状态关联次态。禁止使用MEALY_STATE_UNKNOWN。
	char next;
	/// @brief 与当前状态关联动作，在转换状态后调用。注意：
	/// 1、实现动作时禁止调用下列函数：wt_mealy_raise。
	/// 2、如果不需要动作使用NULL代替。
	void(*action)(char from, char to, char event, size_t parameter);
} wt_mealy_transition_t;

/// @brief 状态机控制块。
typedef void* wt_mealy_t;

/// @brief 创建新的状态机。
/// @return 返回新创建的状态机。如果由于内存资源不足会导致创建失败，返回NULL。
wt_mealy_t wt_mealy_create(void);

/// @brief 启动状态机。
/// @param mealy 状态机。
/// @param transitTable 状态转换表。
/// @param transitCount 状态转换表数量。
/// @param initialState 起始状态。
/// @param finalState 最终状态。
void wt_mealy_start(wt_mealy_t mealy, const wt_mealy_transition_t* transitTable, unsigned short transitCount, char initialState, char finalState);

/// @brief 向状态机引发事件并返回状态转换后的状态。如果转换失败，状态会保持在当前状态。
/// @param mealy 状态机。
/// @param event 事件。
/// @param parameter 事件关联参数。
/// @return 返回状态转换后的状态，可以与finalState比较，判断状态机是否进入了最终状态。如果返回MEALY_STATE_UNKNOWN表示当前状态不支持该事件。
char wt_mealy_raise(wt_mealy_t mealy, char event, size_t parameter);

/// @brief 获取状态机的当前状态。
/// @param mealy 状态机。
/// @return 返回状态机的当前状态，可以与finalState比较，判断状态机是否进入了最终状态。
char wt_mealy_get_current(wt_mealy_t mealy);

/// @brief 删除并释放状态机所占用资源。
/// @param mealy 状态机。
void wt_mealy_delete(wt_mealy_t mealy);

/// @brief 设置状态机进入最终状态时的回调函数。
/// @param mealy 状态机。
/// @param callback 回调函数。
void wt_mealy_set_final(wt_mealy_t mealy, void(*callback)(void));

/// @brief 获取状态机的当前版本号。
char* wt_mealy_get_version(void);
#endif // !__MEALY_H__

