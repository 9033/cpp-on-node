#include <iostream>
#include "shared.h"
#include <cstdlib>
#include <cmath>
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
        const double aa = *(double*)a;
        const double bb = *(double*)b;
        const double t = std::fdim(aa, bb);
        std::cout << t << ' ' << (t > 0) << std::endl;
        // std::cout << std::sprintf("%0.15e %0.15e %0.15e\n", ssss, aa, bb, t) << ' '<< (t > 0) << std::endl;
        // return (int)t;
        // const double t = *(double*)a - *(double*)b;
        // std::printf("%0.15l %0.15l %0.15l %d\n", *(double*)a, *(double*)b, t, t < 0);
        // // std::cout << *(double*)a << *(double*)b << t << std::endl;
        if(t > 0.0f)return 1;
        else if(t < 0.0f)return -1;
        return 0;
    });
    return add;
}
