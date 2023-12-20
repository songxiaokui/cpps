//
// Created by 宋晓奎 on 2023/12/20.
//

#include "mymutable.h"

void MyMutable::update(const MyMutable &f, string n) {
    f.name = n; // 注意: 若 成员变量name 不使用说明符号 mutable ，此处将报错
    cout << "更新后的名字为: " << f.name << endl;
}