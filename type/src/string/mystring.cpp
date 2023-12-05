//
// Created by 宋晓奎 on 2023/12/1.
//

#include "mystring.h"
#include <cstring>
#include <string>

void testString() {
    using namespace std;
    // string 使用的两种方式
    // 1. C方式
    char str1[] = "hello world";
    cout << str1 << endl;

    // 2. C++方式
    string str2{"hello string"};
    cout << str2 << endl;

    // 3.字符串数组
    // sizeof 计算字符串数组长度
    // strlen 计算存储在数组中字符长度，不包含空字符'\0'
    /*
    const int size{20};
    char name[size]{};
    char fod[size]{};
    cout << "Input you name: " << endl;
    cin.get(name, size).get();
    cin.clear();
    cout << "Input you food: " << endl;
    cin.getline(fod, size);
    cout << "your name " << name << ", you like food is: " << fod << endl;
    cout << "fod array length: " << sizeof fod << endl;
    cout << "fod char length: " << strlen(fod) << endl;
     */

    // 混合输入问题
    /*
    cout << "your build year: " << endl;
    int year{};
    // cin >> year;
    // or
    (cin >> year).get();
    cout << "your streets address: " << endl;
    char address[80]{};
    // cin.getline(address, 80);
    // cin.get();
    cin.getline(address, 80);
    cout << "your build year " << year << " your streets" " is " << address << endl;
    // address 为空
    // 原因: cin读取后 将换行符号留在输入队列中 cin.getline()获取到输入符号 认为输入为空行 就把空字符赋值给address

     */

    /*
    string name{};
    cout << "input your name: " << endl;
    cin >> name;
    cout << "your name is " << name << endl;
    cout << "second letter is " << name[1] << endl;
     */

    // 数组初始化 C++
    /*
    char myName[] = {"我是austin"};
    char myName1[] {"我是Erubus"};
    string a1 = {"hello world"};
    string a2 {"dddd"};
    cout << "myName: " << myName << endl;
    cout << "myName1: " << myName1 << endl;
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;

     */

    /*

    // 字符串的赋值 拼接 附加
    // char 类型数组不允许将一个数组赋值给一个数组
    char b1[20];
    char b2[20] = "asxksss";
    // b1 = b2;  // 非法操作
    string c1;
    string c2{"sxk"};
    c1 = c2;
    cout << "c1: "<< c1 << endl;

    // 拼接
    string c3 = {"hello world "};
    c1 = c3 + c2;
    cout << "c1: "<< c1 << endl;

    c3 += "ddd";
    cout << "c3: "<< c3 << endl;

    // 字符串copy
    std::strcpy(b1, b2);
    cout << "copy b2 to b2, b1: " << b1 << endl;
    // 字符串append
    char b4[] = {"sxk hhhhhh"};
    std::strcat(b1, b4);
    cout << "cat b4 to b1, b1: " << b1 << endl;

    // 获取字符串长度两种方法 stringObj.size()
    // c风格字符串 strlen(stringObj)
    cout << "c3 length: " << c3.size() << endl;
    cout << "b4 length: " << std::strlen(b4) << endl;

    // c风格字符串可以使用cin.getline接受
    char d1[20]{};
    cout << "input c style string: "<< endl;
    cin.getline(d1, 20);
    cout << "d1: " << d1 << endl;

    // c++ string class
    string d2{};
    cout << "input c++ style string: "<< endl;
    getline(cin, d2);
    cout << "d2: " << d2 << endl;
     */

    /*
    // 使用普通赋值方法给string赋值会发生什么
    string d3{};
    cout << "input string: " << endl;
    cin >> d3;
    cout << "d3: " << d3 << endl;
    // input: "skd dd"
    // output: d3: "skd
    // 只会输出一个word
     */

    // 其他形势的字符串字面值
    // 宽字符 需要增加前缀L
    wchar_t f1[] = L"我是大帅比";

    // char16_t 2字节字符 需要增加前缀 u
    char16_t f2[] = u"我是大帅比";

    // char32_t 4字节字符 需要增加前缀 U
    char32_t f3[] = U"我是大帅比";

    // TODO 暂时不知道如何输出

    // Raw字符串 原生字符串
    string e1 = R"(("sxk" \n \t)\" 1111 333 \n*^d))";
    cout << e1 << endl;
    // 自定义限界符号
    string e2 = R"+sxg"(dd axxx\nddjadkfa\a)+sxg"";
    // 自定义的格式
    // R"分界符号"(原生字符串)分界符号""
    cout << e2 << endl;
    string e3 = R"xxxd"(dddd)xxxd"";
    cout << e3 << endl;
}
