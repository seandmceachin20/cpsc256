#include<iostream>

using namespace std;

// write main program
double add(double x, double y) {

    double z = x + y;

    return z;

}

int main(int argc, char** argv) {

    // write code here
    cout << "Hello World!!!!\n";
    double x = 10.0, y = 20.0;
    double z = add(x,y);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return (EXIT_SUCCESS);
}
