#include <iostream>
#include <cstdlib>
#include <vector>

#include "recrusive_permutation.h"

using namespace std;

void recursion(vector<int>& current, int start, int size, int limit);

int main() {
    int limit, size;
    cin >> limit >> size;
    vector<int> store;
    recursion(store, 1, size, limit);
    return 0;
}

void recursion(vector<int>& current, int start, int size, int limit) {
    if (current.size() == size) {
        for (int i=0; i<current.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << current[i];
        }
        cout << endl;
        return;
    }

    for (int i=start; i<=limit; i++) {
        current.push_back(i);
        recursion(current, i+1, size, limit);
        current.pop_back();
    }
}

