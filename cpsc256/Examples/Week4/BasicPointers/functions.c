#include <stdio.h>
#include <stdlib.h>

void swap(int* p1, int* p2) {

    /*
     * The purpose of this function is to swap/exchange the values
     * stored at the memory locations p1 and p2.
     * Remember, the arguments of this function are pointers to
     * locations in memory
     */

    printf("location pointed to by p1 = %p, location pointed to by p2 = %p\n", p1,p2);


    /*
     * Step 1: get the value that is stored at the memory location p1 and
     * store it in a temporary variable
     */

    int temp = *p1;

    /*
     * Step 2: Take the value that is stored at memory location p2, and put
     * that value into memory location p1
     */

    *p1 = *p2;

    /*
     * Step3:  Take the temporary value, and store that at memory location p2
     */
    *p2 = temp;

}

char getCharPointer(char* someString, int n) {

    /* A function to return the n-th character of a string
     * Notice that we pass the string from the main program, but
     * the argument of the function is a pointer to that string, which is of course
     * a pointer to the first character in the character array.
     */

    printf("The address of someString[0] is %p.\n",someString);

    char* pa = &someString[n-1];
    char* pb = someString + (n-1)*sizeof(char);
    printf("%p %p\n",pa,pb);

    char thisChar = *pa;
    char thisChar2 = *pb;
    printf("%c %c\n",thisChar,thisChar2);

    //char thisChar = someString[n-1];

    return thisChar;

}

char getChar(char someString[], int n) {

    /* A function to return the n-th character of a string
     * Notice that we pass the string from the main program, and the
     * argument here is a char array, which makes sense.  So, in the local
     * function an entire copy of the char array is created locally.
     */

    printf("The address of someString[0] is %p.\n",&someString[0]);

    char thisChar = someString[n-1];

    return thisChar;

}

void changeChar(char* someString, int n, char someChar) {

    char* pa = &someString[n-1];
    *pa = someChar;

}

void swapNumber(double* x, int n1, int n2) {

    double temp = x[n1-1];
    x[n1-1] = x[n2-1];
    x[n2-1] = temp;

}

void swapNumberCopy(double x[], int n1, int n2) {

    double temp = x[n1-1];
    x[n1-1] = x[n2-1];
    x[n2-1] = temp;

}