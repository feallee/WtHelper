/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʹ�õ�����ʵ�ֵ������ʱ�����ǳ�������Ƕ��ʽӦ�á�
 *
 * ģ����
 * ��ʱ�����������ޣ����ڴ���Դ���ƣ���
 * ����ģʽ������(Ĭ��)���ظ���
 *
 * ע������
 * 1��Ϊ�˱����ڴ�й©������ʹ�õ������ʱ������ú���wt_timer_deleteɾ�����ͷ���ռ����Դ��
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com ����.
 *
 */
#ifndef __WT_TIMER_H_

/// @brief �����ʱ�����ƿ顣
typedef void* wt_timer_t;

/// @brief ���������ʱ����
/// @param interval ʱ������
/// @param ʱ�䵽��ص���
/// @return ���ش����������ʱ�����������ʧ�ܣ�����NULL��
wt_timer_t wt_timer_create(unsigned int interval, void(*timed)(void));

/// @brief �������������ʱ����ʱ�䡣
void wt_timer_refresh(void);

/// @brief ִ�����������ʱ����ʱ��ﵽ�ص�������
void wt_timer_dowork(void);

/// @brief ��λ�����ʱ����ʱ�䡣
/// @param timer �����ʱ����
void wt_timer_reset(wt_timer_t timer);

/// @brief ɾ�����ͷ���ռ����Դ��
void wt_timer_delete(wt_timer_t timer);
#endif // !__WT_TIMER_H_
