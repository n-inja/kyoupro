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

const long long PRIME = 1000000007;

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

long long n;
vector<pair<long long, long long>> a;

bool solve(long long val) {
  vector<int> c(n);
  for(int i = 0; i < n; i++) {
    if(val - a[i].first < 0) return false;
    long long b = (val - a[i].first) / a[i].second;
    if(b >= n) b = n - 1;
    c[b]++;
  }
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += c[i];
    if(sum > i + 1) return false;
  }
  return true;
}

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  long long up = 200000000000000;
  long long down = 0;
  while(up - down > 1) {
    // cout << up << " " << down << endl;
    if(solve((up + down) / 2)) up = (up + down) / 2;
    else down = (up + down) / 2;
  }
  cout << up << endl;
  return 0;
}
