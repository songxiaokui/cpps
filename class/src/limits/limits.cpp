//
// Created by 宋晓奎 on 2023/12/11.
//

#include "limits.h"

class Person {
    // 公共权限
public:
    string name;

    void update() {
        this->name = "张三";
        this->m_car = "宝马";
        this->password = "123456";
    }

    // 保护权限
protected:
    string m_car;
    // 私有权限
private:
    string password;
};


int *sum_array(const int* arr, int n);
int sum_array2(const int* start, const int* end);

void testLimits() {
    Person p;
    p.name = "张三";
    // p.m_car = "奔驰";  // 不可以访问

    int arr[8] = {1, 3, 5, 2, 5, 4, 3, 4};
    int *total = sum_array(arr, 8);
    cout << "total= " << *total << endl;
    cout << "total= " << *total << endl;

    // 数组与指针之间的转换关系
    // arr[i] == *(arr+i)
    // &arr[i] == arr+i
    cout << (*(arr+1) == (arr[1])) << endl;
    cout << (&arr[1] == arr+1 ) << endl;

    cout << "sum_array2: " << sum_array2(arr, arr+8) << endl;

    // 常量指针
    int a(10);
    const int* p1 = &a;
    // 下面操作是不被允许的
    // *p1 = 10;
    // 要修改值 只能通过a变量修改
    cout << "a=" << *p1 << endl;
    a = 100;
    cout << "*p1=" << *p1 << endl;

    // 指针常量
    int b;
    int* const pt2 = &b;
    // 下面的操作不被允许
    // pt2 = &a;

}

int *sum_array(const int arr[], int n) {
    int *total = new int;
    for (int i = 0; i < n; i++) {
        // arr[0] = 10;  // 常量指针 保护数据不随便被篡改
        *total += arr[i];
    }
    return total;
}

int sum_array2(const int* start, const int* end)
{
    // 指针减法得到是数组的长度
    cout << "指针减法: " << end - start << endl;

    const int* p = nullptr;
    int total(0);
    for (p = start; p != end; p++)
    {
        total += *p;
    }
    return total;
}