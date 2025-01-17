/*
 * Exercise 5
 * 
 * Create a simple C program that implements a function called add() and takes in 3 integerrs and returns their sum. The integers should be passed by reference
 *
 * 
 */

#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    int sum = add(&a, &b, &c);
    printf("%d + %d + %d = %d\n", a, b, c, sum);
}