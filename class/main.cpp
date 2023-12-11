//
// Created by 宋晓奎 on 2023/12/11.
//

#include "main.h"

void func(...);
void func(int a, int b)
{
    cout << a+b << endl;
}

int main() {
    cout << "this is class module..." << endl;

    // bass
    //  testCircle();

    // cube
    // testCube();

    // func(1,3);

    // testLimits();

    testFunc();
    return 0;
}
