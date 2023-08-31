#include<stdio.h>

void swap_values_copy(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("a=%d b=%d \n",a,b);
}

void swap_values(int* a, int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("a=%d b=%d \n",*a,*b);
}

int minarray(int arr[], int size){
    int min=arr[0];
    int i=0;
    for(i=1;i<size;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }//end of for
    return min;
}//end of function

void sort_array(int arr[], int size){
    int i=0,j=0,temp=0;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }//end of if
        }//end of inner for
    }//end of outer for
}//end of function

int main(){


    // Pass by value: The function gets a copy of the value
    // of the variable. Any changes to the variable within
    // the function do not affect the variable in the main function
    int a=10,b=20;
    printf("Main:  Before call to function: a=%d b=%d \n",a,b);
    swap_values_copy(a,b);
    printf("Main:  After call to function: a=%d b=%d \n",a,b);
    printf("\n");

    // Define an array of 6 integers
    int i=0,min=0;
    int numbers[]={4,5,7,3,8,9};//declaration of array
    // Print the array
    for(i=0;i<6;i++){
        printf("numbers[%d]=%d \n",i,numbers[i]);
    }

    // Pass by Reference: The function gets the address of the variable.
    //
    // Call a function which finds the minimum of the array
    // and prints it
    //
    // NOTE: The array is passed by reference, so the function
    // can have access to it, by another name, within the function.
    //
    // A good way to think of pass by reference is that the array name in the function
    // is an alias for the array name in the main function.

    // Note also that we pass the SIZE of the array. This is
    // important, because the function needs to know how many
    // elements are in the array.

    min=minarray(numbers,6);//passing array with size
    printf("minimum number is %d \n",min);
    printf("\n");


    // What if we want to actually change the array in the function?
    // We can do this by passing the array by reference, but it is a little
    // more complicated than passing a single variable by reference.

    // This means that the function must get the address of the array
    // and then can change the values in the array.

    // We do this by passing the address of the array to the function.
    // The function then needs to know that it is getting an address
    // and not a value. We do this by using a pointer.

    // A pointer is a variable that stores an address.
    // We declare a pointer by putting a * after the type.

    // For example:
    int* p;

    // This declares a pointer to an integer.
    // We can assign an address to the pointer by using the & operator.
    // For example:
    p=&a;

    // Now p contains the address of a.
    // We can print the address of a by using the %p format specifier.
    printf("Address of a: %p \n",p);

    // We can also print the value of a by using the * operator.
    printf("Value of a: %d \n",*p);

    // We can change the value of a by using the * operator.
    // This is called dereferencing the pointer.
    printf("Value of a: %d \n",a);
    *p=20;
    printf("Value of a: %d \n",a);
    printf("\n");

    a = 10; b=20;
    printf("Main:  Before call to function: a=%d b=%d \n",a,b);
    swap_values(&a,&b);
    printf("Main:  After call to function: a=%d b=%d \n",a,b);
    printf("\n");

    // Now that we understand a little bit about pointers, let's now pass
    // the array by reference to the function.

    sort_array(numbers,6);
    printf("Sorted array: \n");
    for(i=0;i<6;i++){
        printf("numbers[%d]=%d \n",i,numbers[i]);
    }

    return 0;
}