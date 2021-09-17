#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>

#include "qixiji.h"

using namespace std;

long calculate(int * arr, int size, int average);

int main() {
  int N,M,T;
  cin >> N >> M >> T;

  int * acc_x = (int *)malloc(M * sizeof(int)), * acc_y = (int *)malloc(N * sizeof(int));

  for (int i=0; i<T; i++) {
    int x, y;
    cin >> x >> y;
    acc_x[y-1] ++;
    acc_y[x-1] ++;
  }

  long total_ops = 0;
  if (T % M == 0) {
    total_ops += calculate(acc_x, M, T/M);
    if (T % N == 0) {
      total_ops += calculate(acc_y, N, T/N);
      cout << "both ";
    } else {
      cout << "column ";
    }
  } else {
    if (T % N == 0) {
      total_ops += calculate(acc_y, N, T/N);
      cout << "row ";
    } else {
      cout << "impossible" << endl;
    }
  }

  if (T % M == 0 || T % N == 0) {
    cout << total_ops << endl;
  }

  delete acc_x;
  delete acc_y;

  return 0;
}

long calculate(int * arr, int size, int average) {
  int sum = 0;
  for (int i=0; i<size; i++) {
    sum += arr[i] - average;
    //cout << arr[i] << " " << sum << ",";
    arr[i] = sum;
  }

  //cout << endl;

  sort(arr, arr+size);

  // here if the length is 3, then we use 0, *1*, 2
  // if the length is 4, then we use 0, *1*, 2, 3
  // in both case it is a valid median
  int median_val = arr[(size-1)/2];
  long operations = 0;

  for (int i=0; i<size; i++) {
    operations += abs(median_val - arr[i]);
  }

  return operations;
}
