#include <iostream>
#include <cstdlib>

#include <string.h>

#include "best_cow_fences.h"

using namespace std;

int cows[100000];
int N, F;

bool valid(int * arr, long long bar);

int main() {
    cin >> N >> F;

    long long sum = 0, l = 1, r;
    for (int i=0; i<N; i++) {
        cin >> cows[i];
        cows[i] = cows[i]*1000;
        sum += cows[i];
    }
    r = sum+1;

    while (l+1 < r) {
        long long mid = (l+r)/2;
        int use[N];
        memcpy(use, cows, N * sizeof(int));
        if (valid(use, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}

bool valid(int * arr, long long bar) {
    // cout << bar << endl;
    int arr_length = N;
    // cout << arr_length << endl;
    long long pre[arr_length], sum = 0;
    for (int i=0; i<arr_length; i++) {
        sum += arr[i] - bar;
        // cout << sum << "," << arr[i] << " ";
        pre[i] = sum;
    }
    // cout << endl;

    long long min_pre = 0, max_pre = pre[F-1];
    if (max_pre - min_pre >= 0) {
        return true;
    }
    for (int i=F; i<arr_length; i++) {
        min_pre = min(min_pre, pre[i-F]);
        max_pre = pre[i];
        if (max_pre - min_pre >= 0) {
            return true;
        }
    }

    return false;
}