#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "cinema.h"

using namespace std;

const int N = 200001;
int all_lang[N*3], uni_lang[N*3], acc[N*3], sci[N], audio[N], sub[N], length=0, i=0, uni_length=0;

void discrete() {
    sort(all_lang, all_lang+length);
    for (int i=0; i<length; i++) {
        if (i==0 || all_lang[i] != all_lang[i-1]) {
            uni_lang[uni_length++] = all_lang[i];
        }
    }
}

int find(int x) {
    return lower_bound(uni_lang, uni_lang+uni_length, x) - uni_lang;
}

int main() {
    int n, m;
    cin >> n;

    while (i < n) {
        cin >> sci[i];
        all_lang[length++] = sci[i];
        i++;
    }
    i=0;

    cin >> m;

    while (i < m) {
        cin >> audio[i];
        all_lang[length++] = audio[i];
        i++;
    }
    i=0;

    while (i < m) {
        cin >> sub[i];
        all_lang[length++] = sub[i];
        i++;
    }
    i=0;

    discrete();

    for (; i<n; i++) {
        acc[find(sci[i])] ++; // count number of people who knows each lang
    }
    i = 0;

    int ans = 0, max_happy = 0, max_ok = 0;
    for (; i<m; i++) {
        int happy = acc[find(audio[i])], ok = acc[find(sub[i])];
        if (happy > max_happy) {
            ans = i;
            max_happy = happy;
            max_ok = ok;
        } else if (happy == max_happy) {
            if (ok > max_ok) {
                ans = i;
                max_ok = ok;
            }
        }
    }
    i = 0;

    cout << ans+1 << endl;

    return 0;
}
