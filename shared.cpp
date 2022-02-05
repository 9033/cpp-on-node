// #include <iostream>
#include "shared.h"
#include <cstdlib>
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

double* sort(double *add, int len){
    std::qsort(add, len, sizeof(double), [](const void *a, const void * b){
        if(*(double*)a > *(double*)b)return 1;
        else if(*(double*)a < *(double*)b)return -1;
        return 0;
    });
    return add;
}
