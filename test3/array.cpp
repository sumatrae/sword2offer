#include "pch.h"
#include "array.h"

bool find_number(int* mat, const int32_t cols, const int32_t rows, int number)
{
	//参数检测
	if (nullptr == mat
		|| cols <= 0
		|| rows <= 0)
	{
		std::cout << "input err" << std::endl;
		return false;
	}

	//设置左下角元素为参考元素ref_element
	auto row_index = rows - 1;
	auto col_index = 0;

	//if number == ref_element: return true
	//if number > ref_element: dropout left col
	//if number < ref_element: dropout last row
	while (row_index >= 0
		&& col_index <= cols - 1)
	{
		const auto ref_element_index = cols * row_index + col_index;
		if (mat[ref_element_index] == number)
		{
			return true;
		}
		else if (number > mat[ref_element_index])
		{
			col_index++;
		}
		else
		{
			row_index--;
		}
	}

	return false;
}



