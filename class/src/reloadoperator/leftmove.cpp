//
// Created by 宋晓奎 on 2024/1/9.
//

#include "leftmove.h"

namespace LeftMove
{
    ostream& operator<<(ostream& out, const Person& p)
    {
        out << "类内重载<<输出person信息: " << p.age;
        return out;
    }

    void testLeftMove(void)
    {
        using namespace LeftMove;
        Person p1(10);
        cout << p1 << endl;
    }
}
