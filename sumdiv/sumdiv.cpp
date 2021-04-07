#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

#include "sumdiv.h"

#define ll long long
#define HASH 9901

using namespace std;

vector<pair<ll, ll> > decomp (ll num, ll start);
pair<ll, ll> sum(ll num, ll expo);

int main() {
    ll A, B;
    cin >> A >> B;
    if (A == 0) {
        cout << 0 << endl;
    }
    vector<pair<ll, ll> > decomp_A = decomp(A, 2);
    ll result = 1;
    for (pair<ll, ll>& cur : decomp_A) {
        cur.second *= B;
        //cout << cur.first << "^" << cur.second << endl;
        pair<ll, ll> partial = sum(cur.first % HASH, cur.second);
        result = (result * partial.first) % HASH;
    }

    cout << result << endl;
    return 0;
}

vector<pair<ll, ll> > decomp (ll num, ll start) {
    vector<pair<ll, ll> > result;
    for (ll i=start; i*i<=num; i++) {
        if (num % i == 0) {
            ll next = num, count = 0;
            while (next % i == 0) {
                count ++;
                next /= i;
            }
            result.push_back(make_pair(i, count));
            if (next != 1) {
                vector<pair<ll, ll> > rest = decomp(next, i+1);
                result.insert(result.end(), rest.cbegin(), rest.cend());
            }
            return result;
        }
    }

    result.push_back(make_pair(num, 1));
    return result;
}

pair<ll, ll> sum(ll num, ll expo) { // returns the result of sum(num^expo) and num^expo itself.
    if (expo == 0) {
        return make_pair(1, 1);
    }
    if (expo == 1) {
        int remainder = num;
        return make_pair((remainder+1) % HASH, remainder);
    }

    bool even = expo % 2 == 0;
    ll half = expo/2;
    pair<ll, ll> half_result = sum(num, even ? (half-1) : half);
    if (even) {
        ll coef = half_result.second;
        coef = (coef * (num*num % HASH)) % HASH;
        coef = (coef+1) % HASH;
        ll sum = ((half_result.first) * coef) % HASH + (half_result.second * num) % HASH;
        ll iden = ((half_result.second * num) % HASH) * ((half_result.second * num) % HASH) % HASH;
        return make_pair(sum, iden);

    } else {
        ll coef = half_result.second;
        coef = (coef * num) % HASH;
        coef = (coef+1) % HASH;
        ll sum = ((half_result.first) * coef) % HASH;
        ll iden = (((half_result.second * half_result.second) % HASH) * num) % HASH;
        return make_pair(sum, iden);
    }
}