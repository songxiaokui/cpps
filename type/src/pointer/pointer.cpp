//
// Created by 宋晓奎 on 2023/12/6.
//

#include "pointer.h"

void testPointer(void)
{
    cout << "this is pointer test..." << endl;
    int updates(6);
    int* p_updates(&updates);
    cout << "updates value = " << updates << " this address is: " << &updates << endl;
    cout << "p_updates value = " << *p_updates << " this address is: " << p_updates << endl;
    cout << "address is equ: " << (p_updates == &updates) << endl;

    // int *ptr *ptr是int的值
    // int* ptr 强调的是int*指向int的指针
    // 注意
    int* p1, p2;
    // p1是指针
    // p2是值
    int a(1);
    p1 = &a;
    // p2 = &a; // 报错

    // 对每一个指针变量 都需要加 *

    // 正确姿势
    int* p3, *p4;
    p3 = &a;
    p4 = &a;


 }