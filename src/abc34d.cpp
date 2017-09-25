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

double f(pair<double, double> a) {
  return a.second / (a.first + a.second);
}

pair<double, double> add(pair<double, double> lhs, pair<double, double> rhs) {
  return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<double, double>> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  for(int i = 0; i < n; i++) {
    p[i].second = p[i].first * p[i].second;
    p[i].first -= p[i].second;
  }

  pair<double, double> ans;
  vector<bool> b(n);
  int id = 0;
  for(int i = 1; i < n; i++) {
    if(f(p[id]) < f(p[i])) id = i;
  }
  ans = p[id];
  b[id] = true;
  for(int i = 1; i < k; i++) {
    double ma = 0;
    for(int j = 0; j < n; j++) {
      if(b[j]) continue;
      if(ma < f(add(ans, p[j]))) {
        ma = f(add(ans, p[j]));
        id = j;
      }
    }
    ans = add(ans, p[id]);
    b[id] = true;
  }
  printf("%.9lf\n", f(ans));
  return 0;
}
