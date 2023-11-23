#include "wt_convert.h"
/// @brief 格式化字符串以支持函数 sscanf 解析。注意：
/// @brief  1、给缓冲区 buffer 预留足够的空间避免溢出，因为连续两个分隔符之间会插入一个字符0x7F。
/// @param buffer 字符串缓冲区。
/// @param count 字符串数量。
/// @param separator 分隔符。
/// @return 返回格式化后的字符串数量。
uint32_t wt_convert_scanformat(char* buffer, uint32_t count,const char* separator)
{
	uint32_t ix = 0;
	while (ix < count - 1)
	{
		if (strchr(separator, buffer[ix]))
		{
			if (strchr(separator, buffer[ix + 1]))
			{
				/*整体右移*/
				uint32_t i = count++;
				buffer[i + 1] = 0;
				while (i > ix + 1)
				{
					buffer[i] = buffer[i - 1];
					i--;
				}
				buffer[i] = 0x7F;//填充为0x7F
			}
		}
		ix++;
	}
	return count;
}