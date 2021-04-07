#include <iostream>
#include <cstdlib>
#include <vector>

#include "recursive_iteration.h"

using namespace std;

void recursion(vector<int>& current, int size);

int main() {
    int size;
    cin >> size;
    vector<int> store;
    recursion(store, size);
    return 0;
}

void recursion(vector<int>& current, int size) {
    if (size == 0) {
        for (int i=0; i<current.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << current[current.size()-1-i];
        }
        cout << endl;
        return;
    }
    current.push_back(size);
    recursion(current, size-1);
    current.pop_back();
    recursion(current, size-1);
}