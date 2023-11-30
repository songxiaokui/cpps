//
// Created by 宋晓奎 on 2023/11/29.
//

#include "main.h"
#include <cstdio>

int main() {
    auto code = SayHello();
    printf("hello world");

    int age;
    std::cout << "请输出你的年龄: " << std::endl;
    std::cin >> age;
    using std::cout;
    cout << "你输入的年龄为: " << age << std::endl;
    std::cin.get();
    std::cin.get();
    return 0;
};