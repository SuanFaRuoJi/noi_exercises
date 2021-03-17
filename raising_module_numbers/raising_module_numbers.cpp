#include <iostream>
#include <cstdlib>
#include <string.h>

#include "raising_module_numbers.h"

using namespace std;

bool DEBUG = false;

long long calculate_power_module(long long a, long long b, int p) {
    long long result = a, total = 1;
    long long mask = 1;
    for (; mask <= b; mask <<= 1) {
        if ((mask & b) != 0) {
            total = (total * result) % p;
        }
        result = (result * result) % p;
    }

    return total;
}

int main(int argc, char * argv[]) {
    int cases;
    DEBUG = argc >= 2 && strcmp(argv[1], "debug") == 0;
        cin >> cases;
        if (DEBUG){
            cerr << "Total of " << cases << " cases:" << endl;
        }
        for (int i=0; i<cases; i++) {
            if (DEBUG){
                cerr << "\tCase " << (i+1) << ":" << endl;
            }
            long long p, num_players;
            cin >> p >> num_players;

            if (DEBUG) {
                cerr << "P: " << p << ", # of players: " << num_players << "." << endl;
            }
            long long a, b;
            int result = 0;
            for (int j=0; j<num_players; j++) {
                cin >> a >> b;
                long long local = calculate_power_module(a % p, b, p);
                result = (result + local) % p;
                if (DEBUG) {
                    cerr << "Player " << (j + 1) << ": " << local << ", current total: " << result << endl;
                }
            }
            cout << result << endl;
        }
    return 0;
}

