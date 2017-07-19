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

#define P 1000000007

using namespace std;

int fastpow(int e, int x) {
  if(x == 0) {
    return 1;
  }
  if(x % 2 == 0) {
    return fastpow(e*e, x / 2);
  } else {
    return e * fastpow(e, x - 1);
  }
}

int main() {
  int n;
  cin >> n;
  vector<long long> x;
  x.resize(n);
  for(int i = 0; i < n; i++) cin >> x[i];

  long long l;
  int q;
  cin >> l >> q;
  vector<pair<int, int>> query;
  query.resize(q);
  for(int i = 0; i < q; i++) {
    cin >> query[i].first >> query[i].second;
    if(query[i].first > query[i].second) {
      int tmp = query[i].first;
      query[i].first = query[i].second;
      query[i].second = tmp;
    }
    query[i].first--;
    query[i].second--;
  }
  vector<vector<long long>> path;
  path.resize(n);
  for(int i = 0; i < n - 1; i++) {
    path[i].push_back(x[i + 1] - x[i]);
  }
  for(int k = 1; k < n; k *= 2) {
    for(int i = 0 ; i < n - k*2; i++) {
      path[i].push_back(path[i][k - 1] + path[i + k][k - 1]);
    }
  }

  for(int i = 0; i < q; i++) {
    long long ans = 1, ll = l;
    int now = query[i].first;
    while(true) {
      auto p = upper_bound(path[now].begin(), path[now].end(), ll);
      if(p == path[now].begin()) {
        ll = l;
        ans++;
        continue;
      }
      p--;
      ll -= *p;
      now += fastpow(2, p - path[now].begin());
      if(now >= query[i].second) {
        cout << ans << endl;
        break;
      }
    }
  }
  return 0;
}
