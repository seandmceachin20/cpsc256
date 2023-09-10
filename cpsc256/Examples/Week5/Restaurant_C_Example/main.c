/*
 * File:   main.c
 * Author: brash
 *
 * Created on October 14, 2022, 9:59 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  Simple program to illustrate the use of structures in C
 */

typedef struct Restaurant_struct {
    char name[20];
    int rating;
    char price[5];
    char cuisine[30];
    int id;
} Restaurant;

int main(int argc, char** argv) {
    
    Restaurant moes;
    Restaurant schooners;
    Restaurant mickeydees;
    
    moes.rating = 3;
    schooners.rating = 5;
    mickeydees.rating = 1;

    return (EXIT_SUCCESS);
}

