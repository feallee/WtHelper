/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʹ������ʵ�ֵĻ����������ж��е� FIFO ���ܡ�
 *
 * ģ����
 * ��������������� 32768 �ֽڡ�
 *
 * ע������
 * 1���ڶ������к��� wt_buffer_putchar �� wt_buffer_getchar �ǲ���ȫ�ġ�
 * 2��ģ�鲢û�жԺ�����������⣬��Ҫ���⡣
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/11/21   feallee@hotmail.com ɾ����̬�ڴ��ʹ�ã�������ģ��ͨ���ԣ��Ż���ؽӿڡ�
 * 2023/08/08   feallee@hotmail.com ����.
 */
#ifndef __WT_BUFFER_H_
#define __WT_BUFFER_H_
#include <stdint.h>

 /// @brief ���������ƿ顣
typedef struct
{
	/// @brief ��ȡ�����û������������ڴ�ء�
	uint8_t* pool;
	/// @brief ��ȡ�����û�������������
	int32_t capacity;
	/// @brief ��ȡ�����û�������������ת��־��
	uint16_t read_mirror : 1;
	/// @brief ��ȡ�����û�����������ָ�롣
	uint16_t read_index : 15;
	/// @brief ��ȡ�����û�����д������ת��־��
	uint16_t write_mirror : 1;
	/// @brief ��ȡ�����û�����д����ָ�롣
	uint16_t write_index : 15;
}wt_buffer_type;

/// @brief ��ʼ����������
/// @param buffer ���������ƿ顣
/// @param pool �ڴ�ء�
/// @param capacity ��������������� 32768 �ֽڡ�
void wt_buffer_init(wt_buffer_type* buffer, uint8_t* pool, int32_t capacity);

/// @brief �򻺳���д��һ���ֽ����ݡ�
/// @param buffer ���������ƿ顣
/// @param segment Դ����ָ�롣
/// @return ���سɹ�д�뻺������������
int32_t wt_buffer_write_byte(wt_buffer_type* buffer, const uint8_t segment);

/// @brief �ӻ�������ȡһ���ֽ����ݡ�
/// @param buffer ���������ƿ顣
/// @param segment Ŀ������ָ�롣
/// @return ���سɹ���ȡ��������
int32_t wt_buffer_read_byte(wt_buffer_type* buffer, uint8_t* segment);

#endif