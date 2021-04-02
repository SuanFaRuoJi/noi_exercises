#include <iostream>
#include <cstdlib>
#include <cstring>

#include "switches.h"

using namespace std;

void operate(char matrix [5][5], int i, int j) {
    //cout << i << " " << j << endl;
    //cout << matrix[i][j] << "->";
    matrix[i][j] = matrix[i][j] == '0' ? '1' : '0';
    //cout << matrix[i][j] << ";";
    if (i-1 >= 0) {
        //cout << matrix[i-1][j] << "->";
        matrix[i-1][j] = matrix[i-1][j] == '0' ? '1' : '0';
        //cout << matrix[i-1][j] << ";";
    }
    if (j-1 >= 0) {
        //cout << matrix[i][j-1] << "->";
        matrix[i][j-1] = matrix[i][j-1] == '0' ? '1' : '0';
        //cout << matrix[i][j-1] << ";";
    }
    if (i+1 < 5) {
        //cout << matrix[i+1][j] << "->";
        matrix[i+1][j] = matrix[i+1][j] == '0' ? '1' : '0';
        //cout << matrix[i+1][j] << ";";
    }
    if (j+1 < 5) {
        //cout << matrix[i][j+1] << " ";
        matrix[i][j+1] = matrix[i][j+1] == '0' ? '1' : '0';
        //cout << matrix[i][j+1] << ";";
    }
    //cout << endl;
}

int induct(char matrix [5][5], int initial) {
    //cout << initial << endl;
    int count = 0;
    for (int i=0; initial; initial >>= 1, i++) {
        if (initial & 1) {
            operate(matrix, 0, i);
            count ++;
        }
    }
    for (int i=1; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (matrix[i-1][j] == '0') { // same col 1 row above is off, need to swicth this row
                operate(matrix, i, j);
                count ++;
                if (count > 6) {
                    return -1;
                }
            }
        }
    }
    for (int j=0; j<5; j++) {
        if (matrix[4][j] == '0') {
            return -1;
        }
    }
    return count;
}

int main() {
    int cases;
    char matrix[5][5];
    cin >> cases;
    while (cases) {
        cases --;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> matrix[i][j];
            }
            cin.get();
        }
        cin.get();

        int result = 7;
        for (int i=0; i<32; i++) {
            char copy[5][5];
            for (int row=0; row<5; row++) {
                strncpy(copy[row], matrix[row], 5 * sizeof(char));
            }
            int local = induct(copy, i);
            if (local != -1) {
                result = min(result, local);
            }
        }
        cout << (result > 6 ? -1 : result) << endl;
    }
    return 0;
}
