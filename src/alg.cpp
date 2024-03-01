// Copyright 2022 NNTU-CS
#include "alg.h"
#include <iostream>
#include <cstdint>


double pown(double value, uint16_t n) {
    
    double resPown = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            resPown *= value;
        }
        value = value * value;
        n = n / 2;
    }
    return resPown;

}

uint64_t fact(uint16_t n) {

    double resFact = 1.0;
    for (int i = 2; i <= n; i++) {
        resFact *= i;
    }
    return resFact;
    
}

double calcItem(double x, uint16_t n) {

    double resCalc = pown(x, n) / fact(n);
    return resCalc;

}

double expn(double x, uint16_t count) {

    double resExpnn = 1.0;
    for (int i = 1; i <= count; i++) {
        resExpnn += calcItem(x, i);
    }
    return resExpnn;

}

double sinn(double x, uint16_t count) {

    double resSinn = 0;
    int znak = 1;
    for (int i = 1; i <= count; i += 2) {
        double elementSinn = calcItem(x, i);
        resSinn += znak * elementSinn;
        znak *= -1;
    }
    return resSinn;

}

double cosn(double x, uint16_t count) {

    double resCosn = 0.0;
    for (int i = 0; i < count; i++) {
        double elementCosn = pown(-1, i) * pown(x, 2 * i) / fact(2 * i);
        resCosn += elementCosn;
    }
    return resCosn;

}
