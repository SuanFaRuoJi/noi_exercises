#include <iostream>
#include <cstdlib>

#include <string.h>

#include "best_cow_fences.h"

using namespace std;

int cows[100000];
double pre[100000];
int N, F;

bool valid(double bar);

int main() {
    cin >> N >> F;

    double l = 1, r = 0;
    for (int i=0; i<N; i++) {
        cin >> cows[i];
        r = max(r, (double)cows[i]);
    }

    r+=1;

    while (r - l > 1e-5) {
        double mid = (l+r)/2;
        if (valid(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << (int)(r*1000) << endl;
    return 0;
}

bool valid(double bar) {
    double sum = 0;
    for (int i=0; i<N; i++) {
        sum += cows[i] - bar;
        pre[i] = sum;
    }

    double minv = 0;
    for (int i=F-1; i<N; i++) {
        if (pre[i] - minv >= 0) {
            return true;
        }
        minv = min(minv, pre[i-F+1]);
    }

    return false;
}