//
// Created by 宋晓奎 on 2023/12/6.
//

#include "pointer.h"


void swap(double *dparr, int length, int a, int b);

void swap(double *dparr, int length, int a, int b) {
    cout << "数组长度为: " << length << endl;
    if (a < 0 || a > length || b < 0 || b > length) {
        cout << "数据索引不在范围" << endl;
        return;
    }
    double temp = *(dparr + a);
    *(dparr + a) = *(dparr + b);
    *(dparr + b) = temp;
}

void bubbleSort(int *p, int l);

void bubbleSort(int *p, int l) {
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (*(p + j) > *(p + j + 1)) {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;

            }
        }
    }
}

void printArray(int *p, int l);

void printArray(int *p, int l) {
    for (int i = 0; i < l; i++) {
        cout << p[i] << endl;
    }
}

struct Person {
    string name; // 姓名
    int age;  // 年龄
    char sex;  // 性别
    string hobbyArray[10];  // 动态数组
};

void testPointer(void) {
    cout << "this is pointer test..." << endl;
    int updates(6);
    int *p_updates(&updates);
    cout << "updates value = " << updates << " this address is: " << &updates << endl;
    cout << "p_updates value = " << *p_updates << " this address is: " << p_updates << endl;
    cout << "address is equ: " << (p_updates == &updates) << endl;

    // int *ptr *ptr是int的值
    // int* ptr 强调的是int*指向int的指针
    // 注意
    int *p1, p2;
    // p1是指针
    // p2是值
    int a(1);
    p1 = &a;
    // p2 = &a; // 报错

    // 对每一个指针变量 都需要加 *

    // 正确姿势
    int *p3, *p4;
    p3 = &a;
    p4 = &a;

    // 数组逆置
    int arr1[] = {1, 2, 3, 4, 5};
    int left(0);
    int right(sizeof arr1 / sizeof(int) - 1);
    while (left < right) {
        int temp(arr1[left]);
        arr1[left] = arr1[right];
        arr1[right] = temp;
        left++;
        right--;
    }

    for (int i = 0; i < sizeof arr1 / sizeof(int); i++) {
        cout << arr1[i] << endl;
    }

    // 数组名称的用途
    // 1. 获取数组的长度
    // 2. 获取数组的首地址
    // 3. 数组名代表的是常量 不能进行数组赋值
    int arr2[]{1, 2, 3};
    cout << "数组首地址: " << arr2 << endl;
    cout << "数组首元素地址: " << &arr2[0] << endl;
    cout << "数组第二个首地址: " << &arr2[1] << endl;
    // 指针运算
    cout << "数组第二个地址:" << arr2 + 1 << endl;
    cout << "数组第二个地址的值:" << *(arr2 + 1) << endl;

    // 冒泡排序
    int arr3[]{1, 4, 2, 0, 6, 5, 11};
    int length = sizeof arr3 / sizeof(int);
    for (int i = 0; i < length - 2; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr3[j] > arr3[j + 1]) {
                int temp(arr3[j + 1]);
                arr3[j + 1] = arr3[j];
                arr3[j] = temp;
            }
        }
    }

    cout << "经过冒泡排序后: " << endl;
    for (int i = 0; i < length; i++) {
        cout << arr3[i] << endl;
    }

    // 指针的危险
    // 创建指针对象 只是给指针对象分配了内存 并没有给内存的指针地址初始化
    // int* p5;  // 错误的使用
    int *p5 = new(int);  // 正确
    cout << "p5: " << p5 << endl;
    cout << *p5 << endl;
    int a1(16);
    *p5 = a1;
    cout << *p5 << endl;

    // 二维数组的4种定义方式
    int arr4[2][3];

    int arr5[2][3] = {
            {1, 2, 3},
            {4, 5, 6},
    };

    // 根据行列和数据自动推断
    int arr6[2][4] = {1, 2, 3, 4, 5, 6};

    // 必须指定列数
    int arr7[][4] = {1, 2, 3, 4, 5, 6, 7, 8};

    // 二维数组名称的用途
    cout << "arr7的地址: " << arr7 << endl;
    cout << "arr7第一列的首地址: " << &arr7[0] << endl;
    cout << "arr7第一列第一个元素的首地址: " << &arr7[0][0] << endl;

    // 第一个元素的地址与数组地址相同
    // 计算行列
    cout << "arr7的行数: " << sizeof(arr7) / sizeof(arr7[0]) << endl;
    cout << "arr7的列数: " << sizeof(arr7[0]) / sizeof(arr7[0][0]) << endl;

    // 常量指针与指针常量
    int a11(1);
    int b11(2);
    const int *cp1;
    cp1 = &a11;
    cp1 = &b11;
    // 可以修改指针的指向，一旦指向确定 就不能修改指向的内存地址的值
    // *cp1 = 12;// 报错

    // 常量指针: 修饰的是指针 也就是指针指向的内存地址的值不可修改，但是指针变量的指向可以修改
    // 指针常量: 修饰的是指针变量 指针变量的指向不能更改 但是指针变量指向的地址的值可以修改
    int *const cp2 = &a11; // 初始化就被赋予的指针的指向 所以不能进行修改
    // cp2 = &b11; // 报错 不能修改指向


    // 空指针
    // 空指针就是内存地址为0的指针 只能进行初始化使用 不能对空指针解引用
    int *nullptr1 = NULL;
    // *nullptr1 = 1; // 报错
    // 正确的姿势是要为指针变量分配内存空间
    nullptr1 = new int;
    *nullptr1 = 1;
    cout << "空指针: " << *nullptr1 << endl;

    // 野指针
    // 就是随便给程序赋值了一个不属于程序自己分配的内存地址，没有权限访问
    // double* dp = (double*) 0x1010010;
    // cout << "野指针dp: " << *dp << endl;

    // 指针与函数
    // 值传递(形参的修改不会影响实参)
    // 指针传递(形参的修改会影响实参数)
    double dp1[10] = {1, 3, 4, 2, 5, 9, 0};
    swap(dp1, 10, 1, 4);
    cout << "交换后dp1[1]: " << dp1[1] << endl;
    cout << "交换后dp1[4]: " << dp1[4] << endl;

    // bubbleSort
    int bs1[6] = {0, 4, 2, 5, 9, 7};
    cout << "冒泡排序前: " << endl;
    printArray(bs1, sizeof bs1 / sizeof(int));
    bubbleSort(bs1, sizeof bs1 / sizeof(int));
    cout << "冒泡排序后: " << endl;
    printArray(bs1, sizeof bs1 / sizeof(int));

    // 结构体指针
    // 使用结构体指针 访问成员变量需要用'->'代替'.'
    struct Person  pes1 = {
            .name = "宋晓奎",
            .age = 30,
            .sex = '1',
            .hobbyArray = {"打篮球", "跑步", "深蹲"},
    };

    struct Person* pptr = &pes1;
    cout << "姓名: " << pptr->name << endl;
    cout << "年龄: " << pptr->age << endl;
    cout << "性别: " << pptr->sex << endl;
    for (const auto& p: pptr->hobbyArray)
    {
        if (p.empty() ) {
            continue;
        }
        cout << "爱好为: " << p << endl;
    }
}