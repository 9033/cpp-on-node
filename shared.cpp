// #include <iostream>
#include "shared.h"

// function definition
int add(int a, int b) {
    return a * b;
}

double adds(double *add, int len){
    double result = 0;
    for(int i = 0;i<len;i++){
        result += add[i];
    }
    return result;
}
