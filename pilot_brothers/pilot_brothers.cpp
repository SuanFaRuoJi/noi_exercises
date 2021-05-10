#include <iostream>
#include <cstdlib>
#include <string.h>

#include "pilot_brothers.h"

using namespace std;

int min_val = 17, min_opr[4];

void search(bool mat[4][4], int row, int operations[4], int total);

int modify(bool mat[4][4], int opr, int row);

void modify_single(bool mat[4][4], int col, int row);

int main() {
    bool mat[4][4];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            char opr;
            cin >> opr;
            mat[i][j] = opr == '-';
        }
    }

    int operations[4];
    for (int i=0; i<(1<<4); i++) {
        //cout << i << endl;
        bool mat_copy[4][4];

        memcpy(mat_copy, mat, sizeof mat);
        int num = modify(mat_copy, i, 0);

        operations[0] = i;

        search(mat_copy, 1, operations, num);
    }

    cout << min_val << endl;

    for (int i=0; i<4; i++) {
        int opr = min_opr[i];
        for (int j=3; j>=0; j--) {
            if (opr & (1<<j)) {
                cout << (1+i) << " " << (4-j) << endl;
            }
        }
    }

    return 0;
}

int modify(bool mat[4][4], int opr, int row) {
    int count = 0;
    for (int i=3; i>=0; i--) {
        if (opr & (1<<i)) {
            modify_single(mat, (3-i), row);
            count ++;
        }
    }

    return count;
}

void modify_single(bool mat[4][4], int col, int row) {
    for (int i=0; i<4; i++) {
        mat[i][col] = !mat[i][col];
        mat[row][i] = !mat[row][i];
    }
    mat[row][col] = ! mat[row][col];
}

void search(bool mat[4][4], int row, int operations[4], int total) {
//    for (int i=0; i<4; i++) {
//        for (int j=0; j<4; j++) {
//            cout << mat[i][j] << " ";
//        }
//
//        cout << endl;
//    }
    if (row == 4) {
        for (int i=0; i<4; i++) {
            if (!mat[3][i]) {
                return;
            }
        }
        if (total < min_val) {
            min_val = total;
            memcpy(min_opr, operations, sizeof min_opr);
        }
        return;
    }

    int count = 0, opr = 0;
    for (int i=0; i<4; i++) {
        if (mat[row][i] != mat[row-1][i]) {
            count ++;
            opr |= (1 << (3-i));
        }
    }

    if (count == 1) {
        opr = ~opr;
        total += 3;
    } else if (count == 2) {
        total += 2;
    } else if (count == 3) {
        opr = ~opr;
        total += 1;
    } else if (count == 4) {
        total += 4;
    }

    // cout << total << " " << opr << endl;

    if (count != 0) {
        modify(mat, opr, row);
    }
    operations[row] = opr;

    search(mat, row+1, operations, total);
}
