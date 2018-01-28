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
int n, m;
vector<vector<pair<int, long long>>> p;
vector<long long> x;
set<int> s;

bool dfs(int id, long long pos) {
  if(x[id] != -10000000000 && pos != x[id]) return false;
  if(x[id] != -10000000000) return true;
  x[id] = pos;
  s.insert(id);
  for(int i = 0; i < p[id].size(); i++) {
    if(!dfs(p[id][i].first, pos + p[id][i].second)) return false;
  }
  return true;
}

int main() {
  cin >> n >> m;
  p.resize(n);
  x.resize(n);
  for(int i = 0; i < n; i++) x[i] = -10000000000;
  for(int i = 0; i < m; i++) {
    int l, r;
    long long d;
    cin >> l >> r >> d;
    r--; l--;
    p[l].push_back(make_pair(r, d));
    p[r].push_back(make_pair(l, -d));
  }
  for(int i = 0; i < n; i++) {
    if(x[i] == -10000000000) {
      if(!dfs(i, 0)) {
        cout << "No" << endl;
        return 0;
      }
      vector<long long> y;
      for(auto it = s.begin(); it != s.end(); it++) y.push_back(x[*it]);
      sort(y.begin(), y.end());
      if(y[y.size() - 1] - y[0] > 1000000000) {
        cout << "No" << endl;
        return 0;
      }
      s.clear();
    }
  }
  cout << "Yes" << endl;
  return 0;
}
