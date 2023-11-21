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
#ifndef __WT_CHECK_H_
#define __WT_CHECK_H_
#include <stdint.h>

uint8_t wt_check_cs8(const uint8_t* buffer, uint32_t count);
uint16_t wt_check_cs16(const uint8_t* buffer, uint32_t count);
uint32_t wt_check_cs32(const uint8_t* buffer, uint32_t count);

uint8_t wt_check_bcc(const uint8_t* buffer, uint32_t count);




#endif