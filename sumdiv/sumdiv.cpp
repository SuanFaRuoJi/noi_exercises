#include <iostream>
#include <utility>

#define ll long
#define HASH 9901

using namespace std;

ll sum(ll num, ll expo);
ll calc(ll num, ll expo) {
    ll sum = 1;
    while (expo) {
        if (expo & 1) {
            sum = sum * num % HASH;
        }
        num = num * num % HASH;
        expo >>= 1;
    }

    return sum;
}

int main() {
    ll A, B;
    cin >> A >> B;
    if (A == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (A == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll result = 1;
    for (int i = 2; i <= A; i++) {
        int count = 0;
        while (A % i == 0) {
            A /= i;
            count ++;
        }
        //cout << cur.first << "^" << cur.second << endl;
        if (count) {
            result = (result * sum(i % HASH, count * B)) % HASH;
        }
    }

    cout << result << endl;
    return 0;
}

ll sum(ll num, ll expo) { // returns the result of sum(num^expo) and num^expo itself.
    if (expo == 0) {
        return 1;
    }

    if (expo & 1) {
        return sum(num, expo>>1) * (1 + calc(num, (expo>>1)+1)) % HASH;
    } else {
        return (sum(num, (expo>>1)-1) * (1 + calc(num, (expo>>1)+1)) + calc(num, expo>>1)) % HASH;
    }
}