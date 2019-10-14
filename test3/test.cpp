#include "pch.h"
#include "array.h"


TEST(normal, normal_input)
{
	int mat[][3] = { {0,2,4},
					{1,2,5},
					{4,5,6} };

	auto result = find_number(mat[0], 3, 3, 5);
	EXPECT_EQ(result, true);
}


TEST(normal, within_element)
{
	int mat[][5] = { {0,2,4,5,99},
					{1,2,5,7,101},
					{1,2,6,8,120},
					{20,30,42,50,120},
					{35,45,50,51,125},
					{70,80,100,100,250} };

	auto result = find_number(mat[0], 6, 5, 99);
	EXPECT_EQ(result, true);
}

TEST(normal, without_element)
{
	int mat[][5] = { {0,2,4,5,99},
					{1,2,5,7,101},
					{1,2,6,8,120},
					{20,30,42,50,120},
					{35,45,50,51,125},
					{70,80,100,100,250} };

	auto result = find_number(mat[0], 6, 5, 66);
	EXPECT_EQ(result, false);
}

TEST(Abnormal, input_nullptr)
{
	auto result = find_number(nullptr, 3, 3, 5);
	EXPECT_EQ(result, false);
}
TEST(Abnormal, error_input_scope)
{
	int mat[][3] = { {0,2,4},
					{1,2,5},
					{4,5,6} };

	auto result = find_number(mat[0], 0, 3, 5);
	EXPECT_EQ(result, false);

	result = find_number(mat[0], 3, 0, 5);
	EXPECT_EQ(result, false);
}

