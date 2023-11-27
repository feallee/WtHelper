/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ�������ݼ��麯�����ϡ�
 *
 * ģ����
 *
 *
 * ע������
 *
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/11/21   feallee@hotmail.com ����.
 */
#ifndef __WT_CONVERTER_H_
#define __WT_CONVERTER_H_
#include <stdint.h>
 /// @brief ��ʽ���ַ�����֧�ֺ��� sscanf ������ע�⣺
 /// @brief  1�������� buffer ��Ԥ���㹻�Ŀռ�����������Ϊ���������ָ���֮������һ���ַ�0x7F��
 /// @param buffer �ַ�����������
 /// @param count �ַ���������
 /// @param separator �ָ�����
 /// @return ���ظ�ʽ������ַ���������
uint32_t wt_converter_scanformat(char* buffer, uint32_t count, const char* separator);

/// @brief ��ʮ�������ַ�ת��Ϊʮ��������
uint8_t wt_converter_h2d(uint8_t value);

/// @brief ��ʮ������ת��Ϊʮ�������ַ���
uint8_t wt_converter_d2h(uint8_t value);

/// @brief ��ʮ�������ַ���ת��Ϊʮ�������顣
uint32_t wt_converter_hs2b(uint8_t* buffer, uint32_t count);

/// @brief ��ʮ��������ת��Ϊʮ�������ַ�����ע�⣺
/// @brief  1�������� buffer ��Ԥ�������Ŀռ䣬��Ϊһ���ֽڵ�������Ҫ�������ֽڱ�ʾ��
uint32_t wt_converter_b2hs(uint8_t* buffer, uint32_t count);
#endif