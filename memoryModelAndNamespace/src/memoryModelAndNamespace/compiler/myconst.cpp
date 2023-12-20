//
// Created by 宋晓奎 on 2023/12/20.
//

#include "myconst.h"

extern const int NAME5 = 100;

void showAddress()
{
    cout << "File myconst.h NAME1 address: " << &NAME1 << endl;
}

void showInnerAddress()
{
    cout << "Extern Inner link var address: " << &NAME5 << endl;
}