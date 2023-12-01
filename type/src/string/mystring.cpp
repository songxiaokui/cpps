//
// Created by 宋晓奎 on 2023/12/1.
//

#include "mystring.h"

void testString()
{
    using namespace std;
    // string 使用的两种方式
    // 1. C方式
    char str1[] = "hello world";
    cout << str1 << endl;

    // 2. C++方式
    string str2{"hello string"};
    cout << str2 << endl;
}
