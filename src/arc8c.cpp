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

double dist(pair<double, double> p1, pair<double, double> p2) {
  if((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) == 0) return 0;
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

struct Node {
  int i;
  double t;
};

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.t < rhs.t;
}

vector<double> t;
int n;

bool f(double tm) {
  set<int> s;
  for(int i = 0; i < n; i++) {
    s.insert(i);
  }
  for(int i = 0; i < n; i++) {
    double d = tm - t[i];
    auto it = lower_bound(s.begin(), s.end(), d);
    if(it == s.begin()) return false;
    it--;
    s.erase(it);
  }
  return true;
}

int main() {
  cin >> n;
  vector<pair<double, double>> p(n);
  vector<pair<int, int>> tr(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second >> tr[i].first >> tr[i].second;
  t.resize(n);
  for(int i = 0; i < n; i++) t[i] = 1000000000;
  
  vector<vector<double>> path(n);
  for(int i = 0; i < n; i++) {
    path[i].resize(n);
    for(int j = 0; j < n; j++) {
      double d = dist(p[i], p[j]);
      path[i][j] = d / min(tr[i].first, tr[j].second);
    }
  }
  
  multiset<Node> q;
  Node start{0, 0};
  q.insert(start);
  
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(t[now.i] <= now.t) continue;
    t[now.i] = now.t;
    for(int i = 0; i < n; i++) {
      if(now.i == i) continue;
      Node next{i, now.t + path[now.i][i]};
      if(t[i] <= next.t) continue;
      q.insert(next);
    }
  }
  
  sort(t.begin(), t.end());
  
  /*
  double minA = -1, maxA = 1000000;
  while(maxA - minA > 0.00000001) {
    double m = (maxA + minA) / 2;
    if(f(m)) maxA = m;
    else minA = m;
  }
  */
  
  double ans = 0;
  for(int i = 0; i < n - 1; i++) {
    ans = max(ans, t[n - 1 - i] + i);
  }
  
  printf("%.6lf\n", ans);
  return 0;
}