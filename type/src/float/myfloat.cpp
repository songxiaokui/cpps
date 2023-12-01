//
// Created by 宋晓奎 on 2023/12/1.
//

#include "myfloat.h"

using namespace std;

void typeConvert() {
    // 强制类型转换有3种方式
    // 1. C式风格
    // (typeName) 变量
    float a {1.23f};
    int b = {2};
    b = (int) a;
    cout << "C style " << b << endl;

    // 2. C++式风格
    // typeName (value)
    b = int (a);
    cout << "C++ style " << b << endl;

    // 3. 使用强制类型转换运算符
    // static_cast<typeName> (value)
    b = static_cast<int>(a);
    cout << "static_cast style " << b << endl;
}


void testFloat() {
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (float) 1e7 / (float) 2.37e5 << endl;
    /*
    const int pounds = 14;
    int input;
    cout << "请输入需要转换的磅数: ";
    cin >> input;
    int a1{input / pounds};
    int a2{input % pounds};
    cout << input << "磅经过转换为: " << a1 << "英石" << a2 << "磅" << endl;
    */
    typeConvert();
}