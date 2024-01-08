//
// Created by 宋晓奎 on 2024/1/8.
//

#ifndef CLASS_THISPOINTER_H
#define CLASS_THISPOINTER_H
#include "cstring"
#include "iostream"
using namespace std;


class thispointer {
public:
    string name;
    int age;
    float* fl;

    thispointer();
    thispointer(int age, float* x);
    ~thispointer();
    thispointer(const thispointer& p);

    void setAge(int age);

    thispointer& add(thispointer& tp);
};


#endif //CLASS_THISPOINTER_H

void testThisPointer(void);