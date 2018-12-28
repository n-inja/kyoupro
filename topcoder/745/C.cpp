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

struct Chains2 {
  bool ok(int x, int y, int x2, int y2) {
    if (x == y) {
      return x2 != y2;
    }
    return (x2 < x && y <= y2) || (x2 <= x && y < y2);
  }
  int validate(vector<int> x, vector<int> y) {
    int n = x.size();
    for (int i = 1; i < n; i++) {
      if (!ok(x[i - 1], y[i - 1], x[i], y[i])) {
        return -(i + 1);
      }
    }
    if (n == 1 && x[0] == y[0])
      return 0;
    return y[n - 1];
  }
};

int main() { return 0; }
