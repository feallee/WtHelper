/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʵ����һ�ּ򵥵�����״̬���������������£�
 *	1����ǰĳ���Ѷ�����¼�����ʱ���û���Ҫ���¼��͹������������ú���wt_mealy_raise���ݸ�״̬����
 *	2��״̬�����պ�����״̬ת�������״̬ת����ִ�й����Ķ�����
 *	3����ִ��״̬ת��ʱ�������ǰ״̬�����Ĵ�̬������״̬����״̬��������Ӧ�¼���
 *
 * ģ����
 * ״̬�����������ޡ�
 * ״̬������256����
 * �¼�������256����
 * ת����������65535����
 *
 * ע������
 * 1���ڶ������к���mealy_raise�ǲ���ȫ�ġ�
 * 2��ģ�鲢û�жԺ����������κμ�⣬��Ҫ���⡣
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/11/21   feallee@hotmail.com ɾ����̬�ڴ��ʹ�ã�������ģ��ͨ���ԣ��Ż���ؽӿڡ�
 * 2023/07/31   feallee@hotmail.com ����.
 *
 */

#ifndef __WT_MEALY_H_
#define __WT_MEALY_H_
#include <stdint.h>
#include <stdbool.h>

 /// @brief ״̬ת������ƿ顣
typedef struct
{
	/// @brief ��ȡ������״̬��
	char state;
	/// @brief ��ȡ�������¼���
	char event;
	/// @brief ��ȡ�����ô�״��
	char next;
	/// @brief ��ȡ�����ö�����
	void (*action)(char from, char to, char event, void* parameter);
}wt_mealy_transition_type;

/// @brief ״̬�����ƿ顣
typedef struct
{
	/// @brief ��ȡ������״̬ת����ָ�롣
	wt_mealy_transition_type* table;
	/// @brief ��ȡ������״̬ת����������
	uint16_t count;
	/// @brief ��ȡ��������ʼ״̬��
	char final;
	/// @brief ��ȡ����������״̬��
	char current;
}wt_mealy_machine_type;

/// @brief ��ʼ��״̬����
/// @param table ״̬ת����ָ�롣
/// @param count ״̬ת����������
/// @param initial ��ʼ״̬��
/// @param final ����״̬��
void wt_mealy_init(wt_mealy_machine_type* machine, wt_mealy_transition_type* table, uint16_t count, char initial, char final);

/// @brief ��״̬�������¼���
/// @param event �¼���
/// @param parameter �¼�״̬������
/// @return ����״̬���Ƿ�֧�ִ��¼���
bool wt_mealy_raise(wt_mealy_machine_type* machine, char event, void* parameter);

/// @brief ��ȡ״̬����ǰ״̬��
/// @return ����״̬����ǰ״̬��
char wt_mealy_getstate(wt_mealy_machine_type* machine);

/// @brief ��ȡ״̬���Ƿ�ͣ����
/// @return ����״̬���Ƿ�ͣ����
bool wt_mealy_isfinal(wt_mealy_machine_type* machine);

#endif // !__MEALY_H__

