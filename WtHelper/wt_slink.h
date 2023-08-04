/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * 本模块实现了单链表，非常适用于嵌入式应用。
 *
 * 模块规格
 *
 * 注意事项
 * 1、在多任务中下面的接口函数是不安全的。
 *	wt_slist_initialize
 *	wt_slist_append
 *	wt_slist_insert
 *	wt_slist_remove
 * 
 * 修订日志
 * 日期         作者                内容
 * -------------------------------------------------------------------------
 * 2023/08/02   feallee@hotmail.com 初版.
 *
 */
#ifndef __WT_SLIST_H_
#define __WT_SLIST_H_
 /// @brief 根据编译器定义一个内联宏。
#ifndef WT_INLINE
#define WT_INLINE
#if defined(__ARMCC_VERSION)           /* ARM Compiler */
#define wt_inline                   static __inline
#elif defined (__IAR_SYSTEMS_ICC__)     /* IAR Compiler */
#define wt_inline                   static inline
#elif defined (__GNUC__)                /* GNU GCC Compiler */
#define wt_inline                   static __inline
#elif defined (__ADSPBLACKFIN__)        /* VisualDSP++ Compiler */
#define wt_inline                   static inline
#elif defined (_MSC_VER)
#define wt_inline                   static __inline
#elif defined (__TI_COMPILER_VERSION__)
#define wt_inline                   static inline
#elif defined (__TASKING__)
#define wt_inline                   static inline
#else
#error not supported tool chain
#endif 
#endif // !WT_INLINE

 /// @brief 单链表节点。
struct wt_slist_node
{
	/// @brief 下一节点。
	struct wt_slist_node* next;
};

/// @brief 单链表节点别名。
typedef struct wt_slist_node wt_slist_t;

/// @brief 向单链表设置一个节点。
/// @param l 单链表。
/// @param n 单链表节点。
wt_inline void wt_slist_setnext(wt_slist_t* l, wt_slist_t* n)
{
	l->next = n;
}

/// @brief 向单链表尾部增加一个节点。
/// @param l 单链表。
/// @param n 单链表节点。
wt_inline void wt_slist_append(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next) node = node->next;
	node->next = n;
	n->next = 0;
}

/// @brief 向单链表插入一个节点。
/// @param l 单链表。
/// @param n 单链表节点。
wt_inline void wt_slist_insert(wt_slist_t* l, wt_slist_t* n)
{
	n->next = l->next;
	l->next = n;
}

/// @brief 获取单链表节点数量。
/// @param l 单链表。
/// @return 返回单链表节点数量。
wt_inline unsigned int wt_slist_count(const wt_slist_t* l)
{
	unsigned int len = 0;
	const wt_slist_t* list = l->next;
	while (list)
	{
		list = list->next;
		len++;
	}
	return len;
}

/// @brief 向单链表删除一个节点。
/// @param l 单链表。
/// @param n 单链表节点。
wt_inline wt_slist_t* wt_slist_remove(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next && node->next != n) node = node->next;
	if (node->next) node->next = node->next->next;
	return l;
}

/// @brief 获取单链表第一个节点。
/// @param l 单链表。
/// @return 返回单链表第一个节点。
wt_inline wt_slist_t* wt_slist_first(wt_slist_t* l)
{
	return l->next;
}

/// @brief 获取单链表最后一个节点。
/// @param l 单链表。
/// @return 返回单链表最后一个节点。
wt_inline wt_slist_t* wt_slist_last(wt_slist_t* l)
{
	while (l->next) l = l->next;
	return l;
}

/// @brief 获取单链表是否为空。
/// @param l 单链表。
/// @return 返回单链表是否为空。0 = 不为空；非0 = 为空。
wt_inline int wt_slist_isempty(wt_slist_t* l)
{
	return l->next == 0;
}

#endif 