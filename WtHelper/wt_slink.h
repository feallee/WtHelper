/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʵ���˵������ǳ�������Ƕ��ʽӦ�á�
 *
 * ģ����
 *
 * ע������
 * 1���ڶ�����������Ľӿں����ǲ���ȫ�ġ�
 *	wt_slist_initialize
 *	wt_slist_append
 *	wt_slist_insert
 *	wt_slist_remove
 * 
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/08/02   feallee@hotmail.com ����.
 *
 */
#ifndef __WT_SLIST_H_
#define __WT_SLIST_H_
 /// @brief ���ݱ���������һ�������ꡣ
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

 /// @brief ������ڵ㡣
struct wt_slist_node
{
	/// @brief ��һ�ڵ㡣
	struct wt_slist_node* next;
};

/// @brief ������ڵ������
typedef struct wt_slist_node wt_slist_t;

/// @brief ����������һ���ڵ㡣
/// @param l ������
/// @param n ������ڵ㡣
wt_inline void wt_slist_setnext(wt_slist_t* l, wt_slist_t* n)
{
	l->next = n;
}

/// @brief ������β������һ���ڵ㡣
/// @param l ������
/// @param n ������ڵ㡣
wt_inline void wt_slist_append(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next) node = node->next;
	node->next = n;
	n->next = 0;
}

/// @brief ���������һ���ڵ㡣
/// @param l ������
/// @param n ������ڵ㡣
wt_inline void wt_slist_insert(wt_slist_t* l, wt_slist_t* n)
{
	n->next = l->next;
	l->next = n;
}

/// @brief ��ȡ������ڵ�������
/// @param l ������
/// @return ���ص�����ڵ�������
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

/// @brief ������ɾ��һ���ڵ㡣
/// @param l ������
/// @param n ������ڵ㡣
wt_inline wt_slist_t* wt_slist_remove(wt_slist_t* l, wt_slist_t* n)
{
	wt_slist_t* node = l;
	while (node->next && node->next != n) node = node->next;
	if (node->next) node->next = node->next->next;
	return l;
}

/// @brief ��ȡ�������һ���ڵ㡣
/// @param l ������
/// @return ���ص������һ���ڵ㡣
wt_inline wt_slist_t* wt_slist_first(wt_slist_t* l)
{
	return l->next;
}

/// @brief ��ȡ���������һ���ڵ㡣
/// @param l ������
/// @return ���ص��������һ���ڵ㡣
wt_inline wt_slist_t* wt_slist_last(wt_slist_t* l)
{
	while (l->next) l = l->next;
	return l;
}

/// @brief ��ȡ�������Ƿ�Ϊ�ա�
/// @param l ������
/// @return ���ص������Ƿ�Ϊ�ա�0 = ��Ϊ�գ���0 = Ϊ�ա�
wt_inline int wt_slist_isempty(wt_slist_t* l)
{
	return l->next == 0;
}

#endif 