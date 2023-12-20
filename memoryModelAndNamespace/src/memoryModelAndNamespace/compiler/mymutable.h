//
// Created by 宋晓奎 on 2023/12/20.
//

#ifndef MEMORYMODELANDNAMESPACE_MYMUTABLE_H
#define MEMORYMODELANDNAMESPACE_MYMUTABLE_H

#include <string>
#include <iostream>

using namespace std;

class MyMutable {
public:
    mutable int age;
    mutable string name;  // 使用说明符mutable 就算函数使用const限定 也可以进行更新
public:
    void update(const MyMutable &f, string name);
};

#endif //MEMORYMODELANDNAMESPACE_MYMUTABLE_H
