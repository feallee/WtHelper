/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʵ����һ�ּ򵥵�����״̬�����ǳ�������Ƕ��ʽӦ�á�
 *
 * ģ����
 * ״̬�������ޣ����ڴ���Դ���ƣ���
 * ״̬������255��/״̬����
 * �¼�������256��/״̬��
 * ת����1��/״̬����
 * ת����������65535��/ת����
 * ͣ����֧�֡�
 * ����ת����֧�֡�
 *
 * ע������
 * 1��Ϊ�˱����ڴ�й©������ʹ�õ�״̬������ú���wt_mealy_deleteɾ�����ͷ�״̬����ռ����Դ��
 * 2���ڶ������к���mealy_raise�ǲ���ȫ�ġ�
 *
 * �޶���־
 * ����         ����                ����
 * -------------------------------------------------------------------------
 * 2023/07/31   feallee@hotmail.com ����.
 *
 */

#ifndef __WT_MEALY_H__
#define __WT_MEALY_H__

 /// @brief δ֪״̬��ע�⣺��״̬��������״̬ת������ʹ�á�
#define WT_MEALY_STATE_UNKNOWN	(-1)

/// @brief ״̬ת�����ƿ顣
typedef struct
{
	/// @brief ��ǰ״̬��������ʹ��MEALY_STATE_UNKNOWN��
	char current;
	/// @brief �뵱ǰ״̬�����¼���
	char event;
	/// @brief �뵱ǰ״̬������̬��������ʹ��MEALY_STATE_UNKNOWN��
	char next;
	/// @brief �뵱ǰ״̬������������ת��״̬����á�ע�⣺ʵ�ֶ���ʱ������������к�����mealy_create��mealy_delete��mealy_raise��
	void(*action)(void* parameter);
} wt_mealy_transit_t;

/// @brief ״̬�����ƿ顣
typedef void* wt_mealy_t;

/// @brief �����µ�״̬����
/// @param transitTable ״̬ת����
/// @param transitCount ״̬ת����������
/// @param initialState ��ʼ״̬��
/// @param finalState ����״̬��
/// @return �����´�����״̬���������������ԭ��
///		1���ڴ���Դ���㣻
///		2������transitCountΪ0��
///		3������initialStateΪMEALY_STATE_UNKNOWN��
///		4������finalStateΪMEALY_STATE_UNKNOWN��
///		5������transitTableΪNULL��
///		�ᵼ�´���ʧ�ܣ�����NULL��
wt_mealy_t wt_mealy_create(const wt_mealy_transit_t* transitTable, unsigned short transitCount, char initialState, char finalState);

/// @brief ��״̬�������¼�������״̬ת�����״̬��
/// @param mealy ״̬����
/// @param event �¼���
/// @param parameter �¼�����������
/// @return ����״̬ת�����״̬��������finalState�Ƚϣ��ж�״̬���Ƿ������ͣ��״̬���������MEALY_STATE_UNKNOWN��ʾ��ǰ״̬��֧�ָ��¼���
char wt_mealy_raise(wt_mealy_t mealy, char event, void* parameter);

/// @brief ��ȡ״̬���ĵ�ǰ״̬��
/// @param ״̬����
/// @return ����״̬���ĵ�ǰ״̬��������finalState�Ƚϣ��ж�״̬���Ƿ������ͣ��״̬��
char wt_mealy_getcurrent(wt_mealy_t mealy);

/// @brief ɾ�����ͷ�״̬����ռ����Դ��
/// @param ״̬����
void wt_mealy_delete(wt_mealy_t mealy);
#endif // !__MEALY_H__

