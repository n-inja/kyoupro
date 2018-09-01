#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct P {
  int i, j, cost;
};

int main() {
  int l;
  cin >> l;
  if (l == 2) {
    cout << 2 << " " << 2 << endl;
    cout << 1 << " " << 2 << " " << 1 << endl;
    cout << 1 << " " << 2 << " " << 0 << endl;
    return 0;
  }
  int k = 0;
  while (l > (1 << (k + 1)))
    k++;
  vector<P> ps(2 * k);
  for (int i = 0; i < k; i++) {
    ps[2 * i].i = i + 1;
    ps[2 * i].j = i + 2;
    ps[2 * i].cost = 1 << (k - 1 - i);
    ps[2 * i + 1].i = i + 1;
    ps[2 * i + 1].j = i + 2;
    ps[2 * i + 1].cost = 0;
  }
  l -= (1 << k);
  int sum = (1 << k);
  while (l > 1) {
    int k2 = 0;
    while (l > (1 << (k2 + 1)))
      k2++;
    ps.push_back(P{1, k + 1 - k2, sum});
    sum += (1 << k2);
    l -= (1 << k2);
  }
  if (l == 1) {
    ps.push_back(P{1, k + 1, sum});
  }
  cout << k + 1 << " " << ps.size() << endl;
  for (int i = 0; i < ps.size(); i++) {
    cout << ps[i].i << " " << ps[i].j << " " << ps[i].cost << endl;
  }
  return 0;
}
