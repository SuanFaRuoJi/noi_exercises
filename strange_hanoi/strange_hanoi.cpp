#include <iostream>
#include <cstdlib>
#include <cstring>

#include "strange_hanoi.h"

using namespace std;

int main() {
    int three[13], four[13];
    three[1] = 1;
    memset(four, 0x7f, sizeof four);
    four[1] = 1;
    for (int i=2; i<=12; i++) {
        three[i] = 2 * three[i-1] + 1;
    }

    for (int i=2; i<=12; i++) {
        for (int j=1; j<=i-1; j++) {
            four[i] = min(four[i], three[i-j] + 2*four[j]);
        }
    }
    for (int i=1; i<=12; i++) {
        cout << four[i] << endl;
    }
}
