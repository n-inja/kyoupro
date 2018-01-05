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

int main() {
  int n, C;
  cin >> n >> C;
  vector<int> s(n), t(n), c(n);
  for(int i = 0; i < n; i++) cin >> s[i] >> t[i] >> c[i];
  vector<vector<pair<int, int>>> u(30), v(30);
  for(int i = 0; i < n; i++) u[c[i] - 1].push_back(make_pair(s[i], t[i]));
  for(int i = 0; i < 30; i++) sort(u[i].begin(), u[i].end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {return lhs.first < rhs.first; });
  for(int i = 0; i < 30; i++) {
    if(u[i].size() == 0) continue;
    v[i].push_back(u[i][0]);
    for(int j = 1; j < u[i].size(); j++) if(v[i][v[i].size() - 1].second == u[i][j].first) v[i][v[i].size() - 1].second = u[i][j].second;
    else v[i].push_back(u[i][j]);
    for(int j = 0; j < v[i].size(); j++) v[i][j].first--;
  }

  vector<pair<int, int>> ps;
  for(int i = 0; i < 30; i++) for(int j = 0; j < v[i].size(); j++) ps.push_back(v[i][j]);
  sort(ps.begin(), ps.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {return lhs.first < rhs.first; });
  for(int i = 1; i < 31; i++) {
    vector<int> p(i);
    bool bb = false;
    for(int j = 0; j < ps.size(); j++) {
      bool b = false;
      for(int k = 0; k < i; k++) if(p[k] <= ps[j].first) {
        p[k] = ps[j].second;
        b = true;
        break;
      }
      if(!b) bb = true;
    }
    if(bb) continue;
    cout << i << endl;
    return 0;
  }

  return 0;
}
