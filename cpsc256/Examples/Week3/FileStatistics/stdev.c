#include <stdio.h>
#include <math.h>

double mean(double a[], int na);

double stdev(double b[], int nb) {

    printf("\n");
    printf("stdev: Calling mean function from stdev() ... \n");
    double localmean = mean(b,nb);
    double sum = 0.0;

    for (int i=0;i<nb;i++) {
        sum = sum + pow((b[i]-localmean),2);
    }

    sum = sum / (nb-1);
    double stdev = sqrt(sum);

    printf("stdev: Address of first element of b, in stdev() function: %p\n",b);
    printf("stdev: Address of nb, in stdev() function: %p\n",&nb);
    printf("\n");


    return stdev;
}