#include <iostream>
#include <cstdlib>

#include "inc_dec_sequence.h"

using namespace std;

int main() {
    int n, prev = -1, cur;
    cin >> n;
    long pos = 0, neg = 0;
    while (n--) {
        cin >> cur;
        if (prev != -1) {
            long long diff = cur - prev;
            if (diff > 0) {
                pos += diff;
            } else {
                neg += -diff;
            }
        }

        prev = cur;
    }
    cout << max(pos, neg) << endl;
    cout << abs(pos-neg)+1 << endl;
    return 0;
}
