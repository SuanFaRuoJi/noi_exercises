#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>

#include "fractal_street.h"

#define ll long long

using namespace std;

ll coor[2];

int refer[4][4] = { // in 0 degree order.
        {0,0, -1, 1},
        {0,1, 1, 0},
        {1,1, 1, 0},
        {1,0, -1, -1}
};

void calc(ll index, int rotate, ll size, int entry) {
    if (size == 1) {
        return;
    }

    ll raw_quadrant = index / (size * size / 4);
    ll remainder = index % (size * size / 4);

    int quadrant = entry == 1 ? ((0 + rotate + entry*raw_quadrant)+4)%4 : ((3 + rotate + entry * raw_quadrant)+4)%4;
    // cout << "city: " << rotate << " " << entry << endl;
    // cout << index << " " << refer[quadrant][0] << " " << refer[quadrant][1] << endl;
    coor[0] += refer[quadrant][0] * (size/2);
    coor[1] += refer[quadrant][1] * (size/2);
    int new_rotate = (refer[(entry == 1 ? 0 : 3) + raw_quadrant * entry][3] + rotate) % 4;
    int new_entry = refer[(entry == 1 ? 0 : 3) + raw_quadrant * entry][2] * entry;

    calc(remainder, new_rotate, size/2, new_entry);
}

ll quick_exp(int exp) {
    if (exp == 1) {
        return 2;
    }

    ll half = quick_exp(exp/2);
    return half * half * (exp%2 ? 2 : 1);
}

int main() {
    int num_case;
    cin >> num_case;
    while (num_case--) {
        ll N, a, b;
        cin >> N >> a >> b;


        // cout << N << " " << a << " " << b << endl;
        ll max_size = quick_exp(N);
        // cout << max_size << endl;

        memset(coor, 0, sizeof coor);
        calc(a-1, 0, max_size, 1);
        ll x1 = coor[0]*10, y1 = coor[1]*10;
        // cout << x1 << " " << y1 << endl;

        memset(coor, 0, sizeof coor);
        calc(b-1, 0, max_size, 1);
        ll x2 = coor[0]*10, y2 = coor[1]*10;
        // cout << x2 << " " << y2 << endl;
;
        // cout << sq_result << endl;
        cout << (ll)(hypot((x1-x2), (y1-y2))+0.5) << endl;
    }
  return 0;
}

