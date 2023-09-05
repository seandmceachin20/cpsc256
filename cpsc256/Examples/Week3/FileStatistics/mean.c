#include <stdio.h>

double mean(double a[], int na) {
    double sum = 0.0;
    for (int i=0; i<na; i++) {
        sum = sum + a[i];
    }
    double mean = sum/na;

    printf("\n");
    printf("mean: Address of first element of a, in mean() function: %p\n",a);
    printf("mean: Address of na, in mean() function: %p\n",&na);
    printf("\n");

    return mean;
}