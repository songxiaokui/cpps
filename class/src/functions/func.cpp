//
// Created by 宋晓奎 on 2023/12/11.
//

#include "func.h"
#include <random>

void funcHandler(int (*arr)[4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "data=" << arr[i][j] << endl;
        }
    }
}

void print(const char *data) {
    cout << data << endl;
}

void rangeString(const char *d) {
    while (*d) {
        cout << *d << endl;
        d++;
    }
}

char* returnString()
{
    return "hello WORLD";
}

char* buildString(char c, int n)
{
    char* ptr = new char [n+1];
    ptr[n] = '\0';
    while (n-- > 0)
    {
        ptr[n] = c;
    }
    return ptr; // 返回堆空间数据 谁调用完 记得释放数据
}

struct Input
{
    string Name;
    int ID;
};

struct Output
{
    string Name;
    int scores;
    char greed;
};

Output* HandlerInput(const Input* i)
{
    Output* output = new Output;
    output->Name = i->Name;
    output->greed = 'A';
    output->scores = 100;
    return output;
}

void guessNumber()
{
    // 产生一个随机数
    int number = std::rand() % 100 + 1;
    int guessNumber(0);
    cout << "请输入你要猜测的数据: " << endl;
    while(cin >> guessNumber)
    {
        if (guessNumber == number)
        {
            cout << "恭喜你猜对了" << endl;
            break;
        }
        if (guessNumber > number)
        {
            cout << "猜大了" << endl;
        }

        if (guessNumber < number)
        {
            cout << "猜小了" << endl;
        }
    }
    cout << "游戏结束" << endl;

}

void showString(const string* ptr, int n)
{
    for (int i = 0; i < n ;i++)
    {
        cout << *(ptr+i) << endl;
    }
}

void showArray(const array<string, 3>* ptr)
{
    for (auto begin = ptr->begin(); begin < ptr->end(); begin++)
    {
        cout << *begin << endl;
    }
}

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

void testFunc() {

    // 设置种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    cout << "函数测试" << endl;
    int arr[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12},
    };

    // 包含4个整型的数组的地址
    // int (*arr)[4]
    // funcHandler(arr, 3);

    // 只指定列数 行术就可以自定义
    int arr2[100][4];
    // funcHandler(arr, 100);

    // 字符串的三种C风格
    char str0[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str[] = "hello world";
    char *str1 = "hello world";

    print(str0);
    print(str);
    print(str1);

    rangeString(str0);
    cout << ('\0' == 0) << endl;

    // 返回C风格的字符串
    cout << returnString() << endl;

    char* ps = buildString('A', 10);
    cout << ps << endl;
    delete [] ps;  // 由于是字符数组 所以要删除一块内存空间

    // 结构体做函数参数与返回参数
    Input input = {"sxk", 1};
    auto out = HandlerInput(&input);
    cout << "名称: " << out->Name << " 等级: " << out->greed << " 分数: " << out->scores << endl;
    delete out; // 释放空间

    int a;
    // cin在抽取istream时 如果抽取失败 则会返回一个bool值
    // 如果输入不是int 则下面的输入会终止
    // cin抽取后的返回值仍然时一个istream对象
    // 循环输入数字的方式中可以用

    /*
    while (cin >> a)
    {
        cout << "a=" << a << endl;
    }
     */
    // 可以使用cin.clear() 丢弃掉非法数据 重新进入输入队列中

    // 实操: 猜数字游戏
    // guessNumber();

    // 函数传递结构地址
    // string 赋值给函数
    string ptr[] = {"宋晓奎", "大师兄", "猪八戒"};
    showString(ptr, 3);

    // 函数与array对象
    array<string, 3> a1 = {"宋晓奎", "大师兄", "猪八戒"} ;
    showArray(&a1);

    // 递归
    cout << "斐波那契数据: " << Fibonacci(20) << endl;
}

