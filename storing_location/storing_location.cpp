#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "storing_location.h"

using namespace std;

int location[100000];

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> location[i];
    }

    sort(location, location+N);

    int loc = location[N/2];

    long sum = 0;
    for (int i=0; i<N; i++) {
        sum += abs(location[i] - loc);
    }

    cout << sum << endl;

    return 0;
}
