#include "wt_convert.h"
uint32_t wt_convert_scanformat(char* buffer, uint32_t count, char separator)
{
	uint32_t ix = 0;
	while (ix < count - 1)
	{
		if (buffer[ix] == separator)
		{
			if (buffer[ix + 1] == separator)
			{
				buffer[ix] = ' ';//第一个逗号替换为空格
				/*整体右移*/
				uint32_t i = count;
				buffer[i + 1] = 0;
				while (i > ix + 1)
				{
					buffer[i] = buffer[i - 1];
					i--;
				}
				buffer[i] = 0x7f;//填充为竖线
				count++;
			}
			else
			{
				buffer[ix] = ' ';
			}
		}
		ix++;
	}
	return count;
}