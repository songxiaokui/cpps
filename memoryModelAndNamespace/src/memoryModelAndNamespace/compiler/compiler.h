//
// Created by 宋晓奎 on 2023/12/19.
//

#ifndef MEMORYMODELANDNAMESPACE_COMPILER_H
#define MEMORYMODELANDNAMESPACE_COMPILER_H

#endif //MEMORYMODELANDNAMESPACE_COMPILER_H

#include <iostream>
#include "hide.h"

using namespace std;

#ifndef sxk
#define sxk 1
#endif


#define SXK "SXK"

constexpr int MY_AGE = 12 * 3;

// 在头文件中声明
extern int this_age;

// 声明引入的变量
extern double HIDE_NUMBER;

void Compiler(void);