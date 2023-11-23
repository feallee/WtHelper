#include "wt_convert.h"
/// @brief ��ʽ���ַ�����֧�ֺ��� sscanf ������ע�⣺
/// @brief  1���������� buffer Ԥ���㹻�Ŀռ�����������Ϊ���������ָ���֮������һ���ַ�0x7F��
/// @param buffer �ַ�����������
/// @param count �ַ���������
/// @param separator �ָ�����
/// @return ���ظ�ʽ������ַ���������
uint32_t wt_convert_scanformat(char* buffer, uint32_t count,const char* separator)
{
	uint32_t ix = 0;
	while (ix < count - 1)
	{
		if (strchr(separator, buffer[ix]))
		{
			if (strchr(separator, buffer[ix + 1]))
			{
				/*��������*/
				uint32_t i = count++;
				buffer[i + 1] = 0;
				while (i > ix + 1)
				{
					buffer[i] = buffer[i - 1];
					i--;
				}
				buffer[i] = 0x7F;//���Ϊ0x7F
			}
		}
		ix++;
	}
	return count;
}