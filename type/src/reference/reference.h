//
// Created by 宋晓奎 on 2023/12/8.
//

#ifndef TYPE_REFERENCE_H
#define TYPE_REFERENCE_H

#endif //TYPE_REFERENCE_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using namespace std;
// 函数重载
int add(const int& a, int = 10);
int add(double a, double b);

void testReference(void);
void getLinePractice(void);