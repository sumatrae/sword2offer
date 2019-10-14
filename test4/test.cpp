#include "pch.h"
#include "StringOperation.h"

TEST(abnormal, null_ptr) {
	EXPECT_FALSE(replace_blank(nullptr, 10));
}

TEST(abnormal, illgal_length) {
	char str[] = "I am Felix";
	EXPECT_FALSE(replace_blank(str, 0));
}

TEST(abnormal, no_enough_space)
{
	char str[13] = "I am Felix";
	char target_str[15] = "I%20am%20Felix";
	EXPECT_FALSE(replace_blank(str, 13));
}

TEST(normal, just_enough_space)
{
	char str[15] = "I am Felix";
	char target_str[15] = "I%20am%20Felix";
	EXPECT_TRUE(replace_blank(str, 15));
	EXPECT_STREQ(str, target_str);
}

TEST(normal, enough_space)
{
	char str[18] = "I am Felix";
	char target_str[15] = "I%20am%20Felix";
	EXPECT_TRUE(replace_blank(str, 18));
	EXPECT_STREQ(str, target_str);
}

TEST(normal,head_blank)
{
	char str[18] = " I am Felix";
	char target_str[] = "%20I%20am%20Felix";
	EXPECT_TRUE(replace_blank(str, 18));
	EXPECT_STREQ(str, target_str);
}

TEST(normal, tail_blank)
{
	char str[18] = "I am Felix ";
	char target_str[] = "I%20am%20Felix%20";
	EXPECT_TRUE(replace_blank(str, 18));
	EXPECT_STREQ(str, target_str);
}

TEST(normal, multi_blank)
{
	char str[18] = "I  am Felix";
	char target_str[] = "I%20%20am%20Felix";
	EXPECT_TRUE(replace_blank(str, 18));
	EXPECT_STREQ(str, target_str);
}

TEST(normal, only_blank)
{
	char str[18] = " ";
	char target_str[] = "%20";
	EXPECT_TRUE(replace_blank(str, 18));
	EXPECT_STREQ(str, target_str);
}