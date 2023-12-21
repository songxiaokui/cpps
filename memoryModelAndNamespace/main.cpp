#include <iostream>
#include "main.h"

extern int this_age;
int main() {
    std::cout << "Hello, World!" << std::endl;

    // 编译
    // Compiler();

    // this_age = 9999;
    // cout << "静态持续存储-全局变量: " << this_age << endl;
    // cout << "静态持续存储-常量表达式constexpr使用: " << MY_AGE << endl;

    // 命名空间
    Namespace();
    return 0;
}
