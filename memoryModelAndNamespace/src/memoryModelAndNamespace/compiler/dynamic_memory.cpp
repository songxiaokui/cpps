//
// Created by 宋晓奎 on 2023/12/21.
//

#include "dynamic_memory.h"
#include <new>

double *free_ptr = new double[20];

struct person {
    char *name;
    int age;
};

class myperson {
public:
    myperson() {

    }

    myperson(int d) {
        this->age = d;
    }

    ~myperson() {
        cout << "释放myperson内存地址" << endl;
    }

private:
    int age;
};

char* buffer = new char [512] {'z'};

void testDynamicMemory(void) {
    cout << "动态内存分配" << endl;

    // C++运算符new或者C函数malloc分配的内存为动态内存
    // 动态内存由new和delete控制 不受作用域和链接性规则控制

    // 编译器使用三块独立的内存：
    //      静态变量(分不同的区)
    //      自动变量(使用栈存储)
    //      动态存储(使用堆存储)

    // 1.使用new运算符初始化
    // 内置类型初始化 可以在类型后面加括号 并加上初始值即可
    int *pi = new int(100);
    double *d1 = new double(1.1);
    cout << "inbuilt type initial pi: " << *pi << endl;
    cout << "inbuilt type initial pi: " << *d1 << endl;
    delete pi;
    delete d1;
    // 初始化数组或结构 需要使用大括号的列表初始化
    // 列表
    int *list = new int[10]{1, 2, 3};
    cout << "array initial: " << list << endl;
    cout << "array initial: " << list + 10 << endl;
    delete[] list;
    // 结构
    struct person *p1 = new person{"sxk", 19};
    cout << "struct initial: " << p1->name << endl;
    delete p1;

    // 2. new失败时 可能找不到请求的内存量 返回空指针
    if (p1 == nullptr) {
        cout << "p1 is nullptr" << endl;
    }

    // 3.new:运算符、函数、替换函数
    // new的实质实际上调用了对应的分配函数
    // new int ==> new(sizeof(int))
    // new int [10] ==> new(10* sizeof(int))
    // delete 同理调用了对应的释放函数
    // 可以自定定义替换函数 从而实现调用自己的函数进行内存分配需求

    // 4. 定位new运算符
    // new可以使用指定的地址来进行对象的创建
    // 定位运算符使用 new (内存地址) 类型 [20](可选);
    // 使用:
    // 1. 引入头文件#include<new>
    // 2. 创建一块内存空间
    // 3. 在已有的内存空间内创建对象
    // 4. 释放创建对象
    // 5. 释放内存地址
    // void* 无类型指针 可以指向任何类型的数据地址 通用的指针类型
    int *memory = new int[sizeof(person)];
    cout << "memory address: " << memory << endl;
    myperson *p2 = new(memory) myperson(10);
    cout << "p2 address: " << (void *) p2 << endl;
    p2->~myperson();
    delete[] memory;

    // new 定位运算overwrite buffer
    cout << "重写前 buffer[0]: " << buffer[0] << endl;
    char *arrayList = new(buffer) char[10]{'a', 'b', 'c'};
    cout << "buffer address: " << (void*)buffer << endl;
    cout << "new arrayList address: " << (void*)arrayList << endl;
    cout << "重写后 buffer[0]: " << buffer[0] << endl;
    cout << "new arrayList[0]: " << arrayList[0] << endl;
    delete [] arrayList;
    delete [] buffer;
    // new 定位运算符使用传递给他的地址 它不会跟踪哪些内存单元被使用 也不会查找未使用的内存块
    // 注意
    // new定位运算符如果使用静态内存 那么不能执行释放操作 权限不够
    // 定位new运算符的工作原理:
    //  它将传给它的地址，转换为无类型指针(void*)以便能够赋值给任何指针类型

    void* pv1 = std::malloc(sizeof(double));
    int* pi1 = (int*) pv1;
    char* c1 = (char*) pv1;
    *pi1 = 55;
    cout << "pv1: " << *pi1 << endl;
    cout << "c1: " << c1 << endl;
    std::free(pv1);
}