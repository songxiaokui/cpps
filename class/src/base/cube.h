//
// Created by 宋晓奎 on 2023/12/11.
//

#ifndef CLASS_CUBE_H
#define CLASS_CUBE_H

#endif //CLASS_CUBE_H

#include <iostream>
#include <string>

using namespace std;

void testCube();

class Cube {
private:
    float length{10};
    float width{10};
    float high{10};
public:
    float getLength();
    float getWidth();
    float getHigh();
    void setSize(float a, float b, float c);
    float getArea();
    float getVolume();
    bool isSeam(Cube &f);
};