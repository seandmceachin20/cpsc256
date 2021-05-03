#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream infile("/Users/brash/CLionProjects/uasco/in.dat");
    int N;
    const int size = 30;
    int location[size][size] = {0};
    int newlocation[size][size] = {0};

    infile >> N;
    cout << "N = " << N << endl;
    const int NN = N;
    char dir[NN];
    int x[NN], y[NN];

    for (int i = 0; i < N; i++) {
        infile >> dir[i] >> x[i] >> y[i];
        cout << dir[i] << " " << x[i] << " " << y[i] << endl;
        newlocation[x[i]][y[i]] = i + 1;
    }

    int conflict[NN];
    for (int i=0;i<NN;i++){
        conflict[i]=0;
    }

    bool debug = 1;

    cout << "----------" << endl;

    int moves = 1;

    while (moves > 0) {

        copy(&newlocation[0][0],&newlocation[0][0]+size*size,&location[0][0]);

        moves = 0;
        for (int i = 0; i < N; i++) {
            if (debug) {
                cout << dir[i] << endl;
            }
            if (dir[i] == 'N') {
                //cout << "here North" << endl;
                //cout << location[x[i]][y[i]+1] << endl;
                if (y[i] + 1 < size) {
                    if (location[x[i]][y[i] + 1] == 0) {
                        newlocation[x[i]][y[i] + 1] = i + 1;
                        moves++;
                    } else {
                        dir[i] = 'S';
                        conflict[location[x[i]][y[i] + 1] - 1] =
                                conflict[location[x[i]][y[i] + 1] - 1] + 1 + conflict[location[x[i]][y[i]] - 1];
                    }
                    y[i] = y[i] + 1;
                }
            } else if (dir[i] == 'E') {
                //cout << "here East" << endl;
                //cout << location[x[i] + 1][y[i]] << endl;
                if (x[i] + 1 < size) {
                    if (location[x[i] + 1][y[i]] == 0) {
                        newlocation[x[i] + 1][y[i]] = i + 1;
                        moves++;
                    } else {
                        dir[i] = 'S';
                        conflict[location[x[i] + 1][y[i]] - 1] =
                                conflict[location[x[i] + 1][y[i]] - 1] + 1 + conflict[location[x[i]][y[i]] - 1];
                    }
                    x[i] = x[i] + 1;
                }
            }

        }
        if (debug) {
            cout << "Moves = " << moves << endl;
        }
    }

    cout << "Moves Final Value = " << moves << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << location[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------" << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << newlocation[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Final Answer: " << endl;
    for (int i = 0; i < N; i++) {
        cout << conflict[i] << endl;
    }

    return 0;

}
