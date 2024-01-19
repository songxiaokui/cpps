//
// Created by 宋晓奎 on 2024/1/19.
//

#include "function.h"

// 函数模板
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <class T>
void printArray(const T* data, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << data[i] << "->";
    }
    std::cout << "End" << std::endl;
}

template <class T>
void bubble_sort(T* &data, int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (data[i] > data[j])
            {
                T temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void testFunctionTemplate(void)
{
    int a = 10;
    int b = 20;
    std::cout << ::max<int>(a, b) << std::endl;

    char a1 = 'a';
    char b1 = 'b';
    std::cout << ::max<char>(b1, a1) << std::endl;

    float* l1 = new float [10];
    for (int i = 0; i< 10; i++)
    {
        l1[i] = i;
    }
    ::printArray<float>(l1, 10);

    char* l2 = new char [3]{'s', 'x', 'k'};
    ::printArray<char>(l2, 3);

    delete [] l1;
    delete [] l2;

    int* al = new int [6] {1, 3, 6, 2,4,8};
    ::bubble_sort<int>(al, 6);
    ::printArray(al, 6);
}