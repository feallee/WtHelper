/*
 * Copyright(C) 2023 We as Top team. All rights reserved.
 *
 * ��ģ��ʵ����һ�ּ򵥵�����״̬�����ǳ�������Ƕ��ʽӦ�á������������£�
 *	1����ǰĳ���Ѷ�����¼�����ʱ���û���Ҫ���¼��͹������������ú���wt_mealy_raise���ݸ�״̬����
 *	2��״̬�����պ�����״̬ת�������״̬ת����ִ�й����Ķ�����
 *	3����ִ��״̬ת��ʱ�������ǰ״̬�����Ĵ�̬������״̬����״̬��������Ӧ�¼���
 *
 * ģ����
 * ״̬�����������ޣ����ڴ���Դ���ƣ���
 * ״̬������255��/״̬����
 * �¼�������256��/״̬��
 * ת����1��/״̬����
 * ת����������65535��/ת����
 * ����ת����֧�֡�
 * �л�ת����֧�֡�
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

#ifndef __WT_MEALY_H_
#define __WT_MEALY_H_

 /// @brief δ֪״̬��ע�⣺��״̬��ֹ��״̬ת������ʹ�á�
#define WT_MEALY_STATE_UNKNOWN	(-1)

/// @brief ״̬ת�����ƿ顣
typedef struct
{
	/// @brief ��ǰ״̬����ֹʹ��MEALY_STATE_UNKNOWN��
	char current;
	/// @brief �뵱ǰ״̬�����¼���
	char event;
	/// @brief �뵱ǰ״̬������̬����ֹʹ��MEALY_STATE_UNKNOWN��
	char next;
	/// @brief �뵱ǰ״̬������������ת��״̬����á�ע�⣺
	/// 1��ʵ�ֶ���ʱ��ֹ�������к�����wt_mealy_raise��
	/// 2���������Ҫ����ʹ��NULL���档
	void(*action)(char from, char to, char event, size_t parameter);
} wt_mealy_transition_t;

/// @brief ״̬�����ƿ顣
typedef void* wt_mealy_t;

/// @brief �����µ�״̬����
/// @return �����´�����״̬������������ڴ���Դ����ᵼ�´���ʧ�ܣ�����NULL��
wt_mealy_t wt_mealy_create(void);

/// @brief ����״̬����
/// @param mealy ״̬����
/// @param transitTable ״̬ת����
/// @param transitCount ״̬ת����������
/// @param initialState ��ʼ״̬��
/// @param finalState ����״̬��
void wt_mealy_start(wt_mealy_t mealy, const wt_mealy_transition_t* transitTable, unsigned short transitCount, char initialState, char finalState);

/// @brief ��״̬�������¼�������״̬ת�����״̬�����ת��ʧ�ܣ�״̬�ᱣ���ڵ�ǰ״̬��
/// @param mealy ״̬����
/// @param event �¼���
/// @param parameter �¼�����������
/// @return ����״̬ת�����״̬��������finalState�Ƚϣ��ж�״̬���Ƿ����������״̬���������MEALY_STATE_UNKNOWN��ʾ��ǰ״̬��֧�ָ��¼���
char wt_mealy_raise(wt_mealy_t mealy, char event, size_t parameter);

/// @brief ��ȡ״̬���ĵ�ǰ״̬��
/// @param mealy ״̬����
/// @return ����״̬���ĵ�ǰ״̬��������finalState�Ƚϣ��ж�״̬���Ƿ����������״̬��
char wt_mealy_get_current(wt_mealy_t mealy);

/// @brief ɾ�����ͷ�״̬����ռ����Դ��
/// @param mealy ״̬����
void wt_mealy_delete(wt_mealy_t mealy);

/// @brief ����״̬����������״̬ʱ�Ļص�������
/// @param mealy ״̬����
/// @param callback �ص�������
void wt_mealy_set_final(wt_mealy_t mealy, void(*callback)(void));

/// @brief ��ȡ״̬���ĵ�ǰ�汾�š�
char* wt_mealy_get_version(void);
#endif // !__MEALY_H__

