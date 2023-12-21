//
// Created by 宋晓奎 on 2023/12/19.
//

#ifndef MEMORYMODELANDNAMESPACE_COMPILER_H
#define MEMORYMODELANDNAMESPACE_COMPILER_H

#endif //MEMORYMODELANDNAMESPACE_COMPILER_H

#include <iostream>
#include "hide.h"
#include "inner_static.h"
#include "mymutable.h"
#include "myconst.h"
#include "functionlink.h"
#include "language_link.h"
#include "dynamic_memory.h"

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

struct data {
    char name[20];
    mutable int access;
    int age;
};

// 引入外部链接性常量
extern const int NAME5;

// 定义一个和function link相同内联函数
void owner_func();


//extern "C" {
//    void language_call(int d);
//}

// C语言链接性 给每个函数都有一个符号名 编译器会进行名称矫正或名称修饰
extern "C" {
void language_call(int d);
void my_add(double a, double b);
};

// C++语言链接性
extern "C++" {
void sayHello();
}

// 如果不指定 默认是C++语言链接性
// 如果语言链接性不一样 可能会导致链接时符号找不到 从而产生链接错误
extern double *free_ptr;

class myfloat {
public:
    // 构造函数
    // 无参数构造
    myfloat()
    {
        this->fl = new double ;
        *this->fl = 0;
    }

    // 有参数构造
    myfloat(double &&f) {
        this->fl = new double;
        *this->fl = f;
    }

    // 拷贝构造
    myfloat(const myfloat &f) {
        this->fl = new double;
        *this->fl = *f.fl;
    }

    // 析构函数
    ~myfloat() {
        delete this->fl;
        cout << "数据释放成功" << endl;
    }

    // show
    void showData() {
        cout << "data is " << *this->fl << endl;
    }


private:
    double *fl;
};

void testMyFloat();