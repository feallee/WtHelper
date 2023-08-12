/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʹ�õ�����ʵ����FIFO���С��ǳ�������Ƕ��ʽӦ�á�
 *
 * ģ����
 * �������������ޣ����ڴ���Դ���ƣ���
 * ����������CPU�ֳ���
 *
 * ע������
 * 1��Ϊ�˱����ڴ�й©������ʹ�õĶ�������ú���wt_queue_deleteɾ�����ͷŶ�����ռ����Դ��
 * 2���ڶ������к���wt_queue_enqueue��wt_queue_dequeue�ǲ���ȫ�ġ�
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com ����.
 *
 */
#ifndef __WT_QUEUE_H_
#define __WT_QUEUE_H_

 /// @brief ���п��ƿ顣
typedef void* wt_queue_t;

/// @brief ����һ�����С�
/// @return ���ش����Ķ��С��������NULL����ʾ����ʧ�ܡ�
wt_queue_t wt_queue_create(void);

/// @brief ��������ӵ����еĽ�β����
/// @param queue ���С�
/// @param data ���ݡ�
/// @return ���������������ݵ�������
int wt_queue_enqueue(wt_queue_t queue, size_t data);

/// @brief �Ƴ�������λ�ڶ��п�ʼ�������ݡ�
/// @param queue ���С�
/// @param data ���ݡ�
/// @return ���ض��п�ʼ�����ݵ����������Ϊ0����ʾ����Ϊ�ա�
int wt_queue_dequeue(wt_queue_t queue, size_t* data);

/// @brief ����λ�ڶ��п�ʼ�������ݵ��������Ƴ���
/// @param queue ���С�
/// @param data ���ݡ�
/// @return ���ض��п�ʼ�����ݵ����������Ϊ0����ʾ����Ϊ�ա�
int wt_queue_peek(wt_queue_t queue, size_t* data);

/// @brief ɾ�����ͷŶ�����ռ�õ���Դ��
/// @param queue ���С�
void wt_queue_delete(wt_queue_t queue);

#endif