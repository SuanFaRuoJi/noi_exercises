#include <iostream>
#include <cstdlib>

#include "editor.h"

using namespace std;

class editor_chain {
public:
    editor_chain * next;
    editor_chain * prev;

    int val;

    editor_chain(int v) {
        val = v;
    }
};

int main() {
    editor_chain * head = new editor_chain(-1);


}
