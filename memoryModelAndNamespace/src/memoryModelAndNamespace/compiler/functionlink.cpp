//
// Created by 宋晓奎 on 2023/12/20.
//

#include "functionlink.h"

static void owner_func()
{
    cout << "this is owner function call" << endl;
}

void functionLink(void)
{
    // 函数和链接性
    // 1. C++不允许在函数中定义函数
    // 2. 函数的存储持续性都是静态的 在整个程序执行期间都存在
    // 3. 函数的链接性默认为外部 也就是在文件间共享
    // 4. 可以使用static说明符号 将函数的链接性设置为内部
    // 5. 其他头文件可以使用extern声明函数
    owner_func();

    // 非内联函数,同名 同特征的函数定义在同命名空间下只能有一个，符合单定义规则

}
