//
// Created by 宋晓奎 on 2023/12/20.
//

#ifndef MEMORYMODELANDNAMESPACE_MYCONST_H
#define MEMORYMODELANDNAMESPACE_MYCONST_H

#endif //MEMORYMODELANDNAMESPACE_MYCONST_H
#include <iostream>
const int NAME1 = 1;
const int NAME2 = 2;
const int NAME3 = 3;
const int NAME4 = 4;
using namespace std;
void showAddress();

// 外部链接性
extern const int NAME5;
void showInnerAddress();