//
// Created by 宋晓奎 on 2023/12/6.
//

#include "pointer.h"

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
    int arr6[2][4] = {1,2,3,4,5,6};

    // 必须指定列数
    int arr7[][4] = {1,2,3,4,5,6,7,8};

    // 二维数组名称的用途
    cout << "arr7的地址: " << arr7 << endl;
    cout << "arr7第一列的首地址: " << &arr7[0] << endl;
    cout << "arr7第一列第一个元素的首地址: " << &arr7[0][0] << endl;

    // 第一个元素的地址与数组地址相同
    // 计算行列
    cout << "arr7的行数: " << sizeof(arr7)/sizeof(arr7[0]) << endl;
    cout << "arr7的列数: " << sizeof(arr7[0])/sizeof(arr7[0][0]) << endl;
}