#include <iostream>
#include <cstdlib>
#include <cstring>

#include "shrotest_hamilton_path.h"

using namespace std;

int main() {
    int size;
    int matrix[21][21];
    cin >> size;
    int result[1 << size][21];
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cin >> matrix[i][j];
        }
    }
    memset(result, 0x3f, sizeof(int) * (1<<size) * 21);
    result[1][0] = 0;
    for (int i=1; i < 1 << size; i++) { // at what status
        for (int j=0; j < size; j++) { // at what point
            if (!(i & (1<<j))) { // can't have where ([0,1,2], 3)
                continue;
            }
            for (int k=0; k < size; k++) { // coming from k
                /**
                 * can't have same as j, or where ([0,1,2], 3)
                 */
                if (!(i & (1<<k))) {
                    continue;
                }
                result[i][j] = min(result[i][j], matrix[j][k] + result[i ^ (1 << j)][k]);
            }
        }
    }
    cout << result[(1 << size) - 1][size-1] << endl;
    return 0;
}
