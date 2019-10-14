#include "pch.h"
#include "StringOperation.h"

bool replace_blank(char* str, const int32_t length)
{
	if ((str == nullptr)
		|| (length <= 0))
	{
		return false;
	}

	//遍历字符串，统计空格数、非空格数
	auto original_num = 0;
	auto* p_str = str;
	auto blank_num = 0;
	auto non_blank_num = 0;

	while (original_num < length)
	{
		if ('\0' == *p_str)
			break;
		else if (' ' == *p_str)
		{
			blank_num++;
		}

		original_num++;
		p_str++;
	}

	//根据统计空格数和非空格数，计算空格替换成%20后的字符数，设置移动双指针
	auto total_num = original_num + 2 * blank_num;
	if (total_num > length)
		return false;

	auto* p = str + (original_num - 1);
	auto* q = str + (total_num - 1);

	//移动字符，遇到空格时替换
	auto index = original_num - 1;
	while (index >= 0)
	{
		if (' ' == *p)
		{
			*q-- = '0';
			*q-- = '2';
			*q-- = '%';
		}
		else
		{
			*q-- = *p;
		}

		p--;
		index--;
	}

	return true;
}