#include <iostream>
#include <cstdlib>

#include "floating_point_multiplication.h"

using namespace std;

int main() {
    long long a, b, p;
    while (!cin.eof()) {
        cin >> a >> b >> p;
        long long result = 0;
        for (; b; b >>= 1) {
            if (b & 1) {
                result = (result + a) % p;
            }
            a = (a * 2) % p;
        }
        cout << result << endl;
    }
    return 0;
}
