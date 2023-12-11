//
// Created by 宋晓奎 on 2023/12/11.
//

#include "circle.h"

const float PI = 3.14;

class Circle {
public:
    float radius;

    float calculate() {
        return 2 * PI * this->radius;
    }
};


void testCircle()
{
    Circle c = Circle();
    c.radius = 10;
    cout << "周长为: " << c.calculate() << endl;

}