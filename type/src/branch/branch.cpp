//
// Created by 宋晓奎 on 2023/12/6.
//

#include "branch.h"

using namespace std;

void testBranch(void) {
    cout << "this is branch test..." << endl;

    int mark{90};
    // cin >> mark;
    // if
    if (mark > 80) {
        cout << "优秀" << endl;
        if (mark > 85) {
            cout << "非常优秀" << endl;
        }
    } else if (mark > 60) {
        cout << "良好" << endl;
    } else {
        cout << "不及格" << endl;
    };

    // switch
    char type{'1'};
    // cin >> type;
    switch (type) {
        case 'a':
            cout << "a" << endl;
            break;
        case 'b':
            cout << "b" << endl;
            break;
        default:
            cout << "other" << endl;
            break;
    }

    // 三元(三目)运算
    int a, b, max;
    a = 10;
    b = 20;

    max = a > b ? a : b;
    cout << max << endl;
    (a > b ? a : b) = 100;
    cout << b << endl;

    // while循环
    int number(0);
    while (number < 10)
    {
        cout << "number is: " << number << endl;
        number++;
    }


    // do while循环
    int n2{0};
    do
    {
        cout << "number2 is: " << n2 << endl;
        n2++;
    }
    while (n2 < 10);

    // while 与do while区别是
    // while 先执行判断 再执行循环体
    // do...while 先执行循环体 再执行判断

}