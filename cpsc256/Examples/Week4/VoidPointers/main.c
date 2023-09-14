/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on September 22, 2021, 12:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

void printBytes(int* arr, int n) {
    // this function prints the bytes of an array of integers
    // the format uses hexadecimal notation.
    // for a 32-bit integer (4 bytes), and two hex characters per byte,
    // we should have 8 hex characters per 32 bit integer

    // We pass the array as a pointer (the first element),
    // and the number of elements in the array

    for (int i = 0; i<n; i++) {
        printf("%08x ",arr[i]);
    }
}

void printBytesVoidPointer(void* arr, int n) {
    // this function also prints the bytes of an array of integers
    // but it uses a void pointer
    // the format uses hexadecimal notation, with 2 hex characters per byte
    // We pass the array as a pointer (the first element)

    // We need to cast the void pointer to a char pointer
    // so that we can increment the pointer by 1 byte at a time (char = 1 byte)
    for (int i = 0; i<n; i++) {
        printf("%02x ",((char*)arr)[i]);
    }
}

int main(int argc, char** argv) {

    // Let's look at how 32- and 64-bit integers are stored in memory
    // We will use the printBytes function to print the bytes of an array of integers
    // 32 bits = 4 bytes
    // 64 bits = 8 bytes
    int arr[] = {16, 31, 32, 65 }; // 16 bytes total for the entire array = 4 x 4 bytes
    printBytes(arr, 4);
    printf(" ... Everything works as expected!\n");
    printf("\n\n");

    // Let's now define a new array using long long integers = 64 bits = 8 bytes
    // When we use the printBytes function, we will see that we now have a problem
    // because the printBytes function is expecting 4 bytes per integer, but
    // we have 8 bytes per integer
    long long int arr_long[] = {16, 31, 32, 65}; // 32 bytes total = 4 x 8 bytes
    printBytes(arr_long, 4);
    printf(" ... We have a problem!\n");
    printf("\n\n");

    // So, we need to define a new function that can handle the long long integers
    printBytesVoidPointer(arr_long, 4*sizeof(long long));
    printf("\n\n");
    
    char name[] = "John";
    printBytesVoidPointer(name, 4*sizeof(char));
    
    printf("\n\n");
    printBytesVoidPointer(arr, 4*sizeof(int));

    return (EXIT_SUCCESS);
}

