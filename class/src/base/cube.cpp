//
// Created by 宋晓奎 on 2023/12/11.
//

#include "cube.h"

float Cube::getLength() {
    return this->length;
}

float Cube::getWidth() {
    return this->width;
}

float Cube::getHigh() {
    return this->high;
}

void Cube::setSize(float a, float b, float c) {
    this->length = a;
    this->width = b;
    this->high = c;
}

float Cube::getArea() {
    return 2 * this->length * this->width + 2 * this->length * this->high + 2 * this->width + this->high;
}

float Cube::getVolume() {
    return this->length * this->width * this->high;
}

bool Cube::isSeam(Cube &f) {
    if (f.getLength() == this->length && f.getWidth() == this->width && f.getHigh() == this->high) {
        return true;
    } else {
        return false;
    }
}

void testCube() {
    Cube c1;
    c1.setSize(10, 11, 12);
    cout << "c1的表面积: " << c1.getArea() << endl;
    cout << "c1的体积: " << c1.getVolume() << endl;

    Cube c2;
    c2.setSize(10, 11, 12);
    cout << "c2的表面积: " << c2.getArea() << endl;
    cout << "c2的体积: " << c2.getVolume() << endl;

    cout << "c1 is equl c2: " << c1.isSeam(c2) << endl;
}