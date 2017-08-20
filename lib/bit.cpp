#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  void add(int a, int w) {
    if(a == 0 || a > n) return;
    for(int x = a; x <= n; x += x & -x) bit[x] += w;
  }
  int sum(int a) {
    if(a == 0) return 0;
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
};
