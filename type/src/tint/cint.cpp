//
// Created by 宋晓奎 on 2023/11/30.
//

#include "cint.h"
#define MY_NAME "Austin"

void testInt() {
    short shortData = SHRT_MAX;
    int intData = INT_MAX;
    long longData = LONG_MAX;
    long long llongData = LLONG_MAX;

    using namespace std;
    cout << "short type use: " << sizeof shortData << " .bits" << endl;
    cout << "int type use: " << sizeof intData << " .bits" << endl;
    cout << "long type use: " << sizeof longData << " .bits" << endl;
    cout << "long long  type use: " << sizeof llongData << " .bits" << endl;

    cout << "Maximum Values" << endl;
    cout << "short: " << shortData << endl;
    cout << "int: " << intData << endl;
    cout << "long: " << longData << endl;
    cout << "long long : " << llongData << endl;
    cout << "char: " << CHAR_MAX << endl;

    // C++赋值
    int age(101);
    cout << "age = " << age << endl;
    int alist = {1};
    cout << "alist = " << alist << endl;
    int number{1};
    cout << "number = " << number << endl;
    unsigned int unsignedData{100};
    cout << "unsigned data: " << unsignedData << endl;

    // 无符号
    cout << "无符号与有符号数据" << endl;
    int max = INT_MAX;
    unsigned int b = max;
    max++;
    b++;
    cout << "max + 1: "<< max << endl;
    cout << "b + 1: " << b << endl;

    int min = ZERO;
    unsigned int c = ZERO;
    min--;
    c--;
    cout << "min - 1: "<< min << endl;
    cout << "c - 1: " << c << endl;

    // 字面量输出
    int a1{42};
    int a2{052};
    int a3{0x2a};
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "a3: " << a3 << endl;
    cout << dec << "dec: " << a1 << endl;
    cout << hex << "hex: " << a2 << endl;
    cout << oct << "oct: " << a3 << endl;

    cout << dec << 16UL << endl;

    // char类型
    char c1{'M'};
    cout << "your char: " << c1 << endl;
    cout.put('1');
    cout << 'N' << endl;
    char xx = '\032';
    cout << "xx: " << xx << endl;

    cout << "\aAccess Warning...";

    cout << "K\u00F6ooo" << endl;

    // 宽字符显示(mac不支持)
    wchar_t largeData;
    using std::wcout;
    using std::wcin;
    wcout << L"我 爱 中国";
    // wcin >> largeData;
    wcout << largeData;

    // 宽字符
    wchar_t p{L'p'};
    wcout<< p<<endl;

    std::wcout << L"hello world\n";

    // C++11 新特性 char16_t char32_t 无符号(16\32) 前缀U标识 字符常量 u 16位 U32位
    char16_t ch1 = u'r';
    cout << "char16_t ch1: " << static_cast<int>(ch1) << endl;
    char32_t ch2{U'\U0000222B'};
    cout << "char32_t ch2: " << static_cast<int>(ch2) << endl;

    // bool类型
    bool isReady{true};
    bool isSuccess{false};
    cout << "is ready: " << isReady << endl;
    cout << "is success: " << isSuccess << endl;
    // 隐式转换
    bool d1, d2;
    d2 = -100;
    d1 = 0;
    auto r = d2 == true;
    cout << r << endl;
    auto y = d1 == false;
    cout << y << endl;

    // 限定符号 常量限定符号 const
    const string NAME = "Erubus";
    cout << "const NAME: " << NAME << endl;
    cout << "define MY NAME: " << MY_NAME << endl;

    cout << endl;

};