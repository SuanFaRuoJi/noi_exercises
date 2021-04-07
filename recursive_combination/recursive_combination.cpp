#include <iostream>
#include <cstdlib>
#include <vector>

#include "recursive_combination.h"

using namespace std;

void recursion(vector<int>& current, int visited, int limit);

int main() {
    int size;
    cin >> size;
    vector<int> store;
    recursion(store, 0, size);
    return 0;
}

void recursion(vector<int>& current, int visited, int limit) {
    if (current.size() == limit) {
        for (int i=0; i<current.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << current[i];
        }
        cout << endl;
        return;
    }
    for (int i=0; i<limit; i++) {
        int sig = 1 << i;
        if (visited & (sig)) {
            continue;
        }
        visited |= sig;
        current.push_back(i+1);
        recursion(current, visited, limit);
        current.pop_back();
        visited ^= sig;
    }
}
