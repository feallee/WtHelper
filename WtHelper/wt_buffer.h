/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʹ������ʵ�ֵĻ����������ж��е�FIFO���ܡ��ǳ�������Ƕ��ʽӦ�á�
 *
 * ģ����
 * ������������32768�����ڴ���Դ���ƣ���
 * ����������1�ֽڡ�
 *
 * ע������
 * 1��Ϊ�˱����ڴ�й©������ʹ�õĻ���������ú���wt_buffer_deleteɾ�����ͷŶ�����ռ����Դ��
 * 2���ڶ������к���wt_buffer_putchar��wt_buffer_getchar�ǲ���ȫ�ġ�
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/08/08   feallee@hotmail.com ����.
 *
 */
#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_

 /// @brief ���������ƿ顣
typedef void* wt_buffer_t;

/// @brief ������״̬��
typedef enum
{
	/// @brief ������Ϊ�ա�
	WT_BUFFER_EMPTY,
	/// @brief ������������
	WT_BUFFER_FULL,
	/// @brief �������������Ȳ�Ϊ�գ�Ҳ��������
	WT_BUFFER_HALFFULL,
}wt_buffer_state;

/// @brief ����һ����������
/// @param capacity ������������ֵ��[1,32768]������ȡ4�ı�����
/// @return ���ش����Ļ��������������NULL����ʾ����ʧ�ܡ�
wt_buffer_t wt_buffer_create(unsigned short  capacity);

/// @brief ɾ�����ͷŻ�������ռ�õ���Դ��
/// @param buffer ��������
void wt_buffer_delete(wt_buffer_t buffer);

/// @brief ��ȡ��������״̬��
/// @param buffer ��������
/// @return ���ػ�����״̬��
wt_buffer_state wt_buffer_getsatate(wt_buffer_t buffer);

/// @brief ��������ӵ��������Ľ�β����
/// @param buffer ��������
/// @param data ���ݡ�
/// @return �����򻺳���������ݵ�������
int wt_buffer_putchar(wt_buffer_t buffer, unsigned char data);

/// @brief �Ƴ�������λ�ڻ�������ʼ�������ݡ�
/// @param buffer ��������
/// @param data [out]���ݡ�
/// @return ���ػ�������ʼ�����ݵ����������Ϊ0����ʾ������Ϊ�ա�
int wt_buffer_getchar(wt_buffer_t buffer, unsigned char* data);

/// @brief ����������������ݡ�
/// @param buffer ��������
void wt_buffer_clear(wt_buffer_t buffer);


#endif