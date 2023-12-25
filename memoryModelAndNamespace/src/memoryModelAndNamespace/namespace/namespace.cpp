//
// Created by 宋晓奎 on 2023/12/19.
//

#include "namespace.h"

void usingNameSpace()
{
    Jill::fetch();
    Jack::fetch();

    cout << "Jill:pail = " << Jill::pail << endl;
    cout << "Jack:pail = " << Jack::pail << endl;
}

void Namespace(void)
{
    cout << "This is namespace file ." << endl;
    // 概念理解
    // 1. 声明区域（可以在其中声明的区域）（全局变量的声明区域为所有变量，自动变量的声明区域在当前所在代码块）
    // 2. 潜在作用域（从声明开始一致到声明区域结束）
    // 3. 作用域（变量对程序可见的范围为作用域，同名变量隐藏区域不是作用域）

    // 定义命名空间的函数与变量
    usingNameSpace();
    // 命名空间可以是全局的 也可以位于另一个命名空间 但不能在代码块中
    // 默认情况下 名称空间内声明的名称为外部链接性
    // 全局名称空间：文件级别声明 全局变量就是全局名称空间
    // 使用名称空间的内容: 使用作用域解析运算符 ::

}