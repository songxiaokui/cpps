//
// Created by austsxk on 2023/12/20.
//

#include "language_link.h"

void language_call(int d);

void language_call(int d) {
    printf("language call data is: %d\n", d);
}

void my_add(double a, double b);

void my_add(double a, double b) {
    printf("a+b = %.2f\n", a + b);
}