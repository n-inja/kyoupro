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

#define P 1000000007

using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int main() {
  pair<double, double> ta, tb;
  double t, v;
  int n;
  cin >> ta.first >> ta.second >> tb.first >> tb.second >> t >> v >> n;
  vector<pair<double, double>> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  double ans = 1145141919;
  for(int i = 0; i < n; i++) if(ans > dist(ta, p[i]) + dist(p[i], tb)) ans = dist(ta, p[i]) + dist(p[i], tb);
  if(ans <= v * t) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
