#include <iostream>
#include <cstdlib>
#include <cstring>

#include "laser_bomb.h"

using namespace std;

int main() {
    int num_targets, size;
    cin >> num_targets >> size;
    //cout << num_targets << size << endl;
    int matrix[5001][5001];
    memset(matrix, 0, sizeof matrix);
    int x_min = 5000, y_min = 5000, x_max = 0, y_max = 0;
    for (int i=0; i<num_targets; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        //cout << x << y << val << endl;
        matrix[x][y] += val;
        if (x > x_max) {
            x_max = x;
        }
        if (y > y_max) {
            y_max = y;
        }
        if (x < x_min) {
            x_min = x;
        }
        if (y < y_min) {
            y_min = y;
        }
    }

    // cout << x_min << " " << x_max << " " << y_min << " " << y_max << endl;
    int max = 0;
    for (int i=x_min; i<=x_max; i++) {
        for (int j=y_min; j<=y_max; j++) {
            int current = matrix[i][j];
            int left = i > 0 ? matrix[i-1][j] : 0, up = j > 0 ? matrix[i][j-1] : 0;
            int diag = (i>0) && (j>0) ? matrix[i-1][j-1] : 0;
            matrix[i][j] = current + left + up - diag;
            int left_r = i >= size ? matrix[i-size][j] : 0, up_r = j >= size ? matrix[i][j-size] : 0;
            int diag_r = (i>=size) && (j>=size) ? matrix[i-size][j-size] : 0;
            int local = matrix[i][j] - left_r - up_r + diag_r;
            //cout << i << " " << j << " " << local << endl;

            if (max < local) {
                max = local;
            }
        }
    }
    cout << max << endl;
    return 0;
}
