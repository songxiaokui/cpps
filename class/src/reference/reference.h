//
// Created by 宋晓奎 on 2023/12/12.
//

#ifndef CLASS_REFERENCE_H
#define CLASS_REFERENCE_H

#endif //CLASS_REFERENCE_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

void testReference(void);

void add1(int a, int b);

void add1(double a, double b);

void add1(char *a, int a1, char *b, int a2);

void sink(double &r1);

void sank(const double &r2);

void sunk(double &&r3);

char *left(char *str, int n);

unsigned int left(int a, int n);

template<typename SxkType>
void Swap(SxkType &a, SxkType &b);

template<class T>
void DoubleSort(T *slice, int length);

// 模版重载
// 重载Swap
template<typename T>
void Swap(T a[], T b[], int length);


struct Job1 {
    std::string name;
    int age;
    double price;
};

// 普通模版函数
template <typename T>
void Swap1(T& a, T& b);

// 显示具体化模版函数
template <> void Swap1<Job1> (Job1 &a, Job1 &b);

// 无模版 普通函数
void Swap1(int& a, int& b);

// 函数调用使用更具体
template <class T>
void ShowArray(T arr[], int length);

template <class T>
void  ShowArray(T* arr[], int length);

// 定义的模版
template <typename T>
T my_add(T a, T b);

// 自定义类型
int my_add(int a, int b);

// 多类型模版
template <typename T1, typename T2>
auto MyAdd(T1 a, T2 b)
{
    // C++11中出现的decltype 获取类型 可以根据表达式推测类型
    // decltype 可以是表达式
    // 编译器遇到decltype会遍历一个核对表
    decltype(a+b) ab = a + b;
    return ab;
}