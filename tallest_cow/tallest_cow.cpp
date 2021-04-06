#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>

#include "tallest_cow.h"

using namespace std;

bool cmp_function_1 (pair<int, int> &a, pair<int, int> &b) {
    int first = min(a.first, a.second), second = min(b.first, b.second),
        first_m = max(a.first, a.second), second_m = max(b.first, b.second);
    return first != second ? first < second : first_m > second_m;
}

bool cmp_function_2 (pair<int, int> &a, pair<int, int> &b) {
    int first = min(a.first, a.second), second = min(b.first, b.second),
            first_m = max(a.first, a.second), second_m = max(b.first, b.second);
    return first != second ? first < second : first_m < second_m;
}

int main() {
    int length, max_index, max_height, num_relations;
    cin >> length >> max_index >> max_height >> num_relations;
    vector<pair<int, int> > relations;
    int visible[length][2];
    memset(visible, 0, sizeof visible);
    for (int i=0; i<num_relations; i++) {
        int a, b;
        cin >> a >> b;
        visible[min(a, b)-1][0] = max(a, b)-1;
        visible[max(a, b)-1][1] = min(a, b)-1;
        relations.push_back(pair<int, int>(a-1, b-1));
    }
    sort(relations.begin(), relations.end(), cmp_function_1);

    vector<pair<int, int> > stack;
    int tallest[length];
    memset(tallest, 0, sizeof tallest);
    tallest[max_index-1] = max_height;
    for (auto iter = relations.begin(); iter != relations.end(); iter++) {
        int from = min(iter->first, iter->second), to = max(iter->first, iter->second);
        // cout << "cur: " << from << " " << to << endl;
        while (!stack.empty()) {
            pair<int, int>& tail = stack[stack.size()-1];
            if (max(tail.first, tail.second) > from) {
                break;
            }
            int from = min(tail.first, tail.second), to = max(tail.first, tail.second), use = min(tallest[from], tallest[to]) - 1;
            for (int i = to-1; i>from; i--) {
                if (tallest[i] != 0) {
                    break;
                }
                tallest[i] = use;
            }
            stack.pop_back();
        }
        int use = max_height;
        if (!stack.empty()) {
            pair<int, int>& tail = stack[stack.size()-1];
            // cout << "tail: " << tail.first << " " << tail.second << endl;
            use = min(tallest[tail.first], tallest[tail.second]) - 1;
        }
        if (tallest[from] == 0) {
            tallest[from] = use;
        }
        if (tallest[to] == 0) {
            tallest[to] = use;
        }
        int last = 0;
        use = max_height;
        if (!stack.empty()) {
            pair<int, int>& last_pair = stack[stack.size()-1];
            last = min(last_pair.first, last_pair.second)+1;
            use = min(tallest[last_pair.first], tallest[last_pair.second]) - 1;
        }
        for (int i=from-1; i>=last; i--) {
            if (tallest[i] != 0) {
                break;
            }
            tallest[i] = use;
        }
        stack.push_back(*iter);
    }

    while (!stack.empty()) {
        pair<int, int>& tail = stack[stack.size()-1];
        int from = min(tail.first, tail.second), to = max(tail.first, tail.second), use = min(tallest[from], tallest[to]) - 1;
        for (int i = to-1; i>from; i--) {
            if (tallest[i] != 0) {
                break;
            }
            tallest[i] = use;
        }
        stack.pop_back();
    }
    for (int i=0; i<length; i++) {
        if (tallest[i] == 0) {
            tallest[i] = max_height;
        }
        cout << tallest[i] << endl;
    }
    return 0;
}
