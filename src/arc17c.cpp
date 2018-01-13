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
 
using namespace std;

bool is(int bit, int k) {
  return (bit >> k) & 1;
}

int main() {
  int n;
  long long X;
  cin >> n >> X;
  vector<long long> x, y;
  for(int i = 0; i < min(16, n); i++) {
    long long w;
    cin >> w;
    x.push_back(w);
  }
  for(int i = 0; i < max(0, n - 16); i++) {
    long long w;
    cin >> w;
    y.push_back(w);
  }
  int nx = x.size(), ny = y.size();
  long long xs[1 << nx], ys[1 << ny];
  for(int i = 0; i < (1 << nx); i++) xs[i] = 0;
  for(int i = 0; i < (1 << ny); i++) ys[i] = 0;
  for(int i = 0; i < (1 << nx); i++) {
    for(int j = 0; j < nx; j++) {
      if(is(i, j)) continue;
      xs[i | (1 << j)] = xs[i] + x[j];
    }
  }
  for(int i = 0; i < (1 << ny); i++) {
    for(int j = 0; j < ny; j++) {
      if(is(i, j)) continue;
      ys[i | (1 << j)] = ys[i] + y[j];
    }
  }
  sort(xs, xs + (1 << nx));
  sort(ys, ys + (1 << ny));
  long long ans = 0;
  for(int i = 0; i < (1 << ny); i++) {
    auto it = lower_bound(xs, xs + (1 << nx), X - ys[i]);
    auto it2 = upper_bound(xs, xs + (1 << nx), X - ys[i]);
    ans += it2 - it;
  }
  cout << ans << endl;
  return 0;
}