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

class ArithmeticSequenceDiv1 {
public:
  ArithmeticSequenceDiv1() {}
  int findMinCost(vector<int> x) {
    int n = x.size();
    int ans = 10000000;
    for (int i = -100; i <= 100; i++) {
      for (int j = 0; j < n; j++) {
        int a = 0;
        for (int k = 0; k < n; k++) {
          if (k == j)
            continue;
          a += abs(x[k] - (x[j] + i * (k - j)));
        }
        ans = min(a, ans);
      }
    }
    return ans;
  }
};

int main() {
  vector<int> x;
  x.push_back(11);
  x.push_back(33);
  x.push_back(22);
  ArithmeticSequenceDiv1 a;
  cout << a.findMinCost(x) << endl;

  return 0;
}
