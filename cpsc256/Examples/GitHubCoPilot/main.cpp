#include "iostream"
using namespace std;

double add(double a, double b) {
  return a + b;
}

int main(int argc, char** argv) {
  // write code here
  cout << "Hello World!" << endl;

  double x = 1.0;
  double y = 2.0;
  double z = add(x, y);
  cout << "z = " << z << endl;

  return 0;
}