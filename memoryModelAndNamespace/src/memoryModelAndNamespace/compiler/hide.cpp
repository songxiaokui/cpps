//
// Created by 宋晓奎 on 2023/12/20.
//

#include "hide.h"

// 定义
extern double HIDE_NUMBER = 1;

void my_update(double &f) {
    show();
    f += 1;
    show();
    cout << "my_update: 在函数内部更新数据 extern" << endl;
    extern double HIDE_NUMBER;
    HIDE_NUMBER += 1000;
    cout << "my_update: Update global HIDE_NUMBER: " << HIDE_NUMBER << endl;
}

void local() {
    cout << "local函数: 局部变量隐藏全局变量" << endl;
    double HIDE_NUMBER = -1.1111;
    cout << "local函数：局部变量 HIDE_NUMBER: " << HIDE_NUMBER << endl;
    // 使用作用域解析运算符 将不展示局部变量而时展示全局变量
    cout << "local函数: 全局变量 ::HIDE_NUMBER: " << ::HIDE_NUMBER << endl;
}

void show()
{
    cout << "show函数: 简单查询全局变量HIDE_NUMBER： " << HIDE_NUMBER << endl;
}