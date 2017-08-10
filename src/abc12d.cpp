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

const int MAX_COST = 1145141919;

class N {
public:
  int now, d;
  N(int n, int c) {
    now = n;
    d = c;
  }
  bool operator>(const N &rhs) const {
    return this->d > rhs.d;
  }
  bool operator<(const N &rhs) const {
    return this->d < rhs.d;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v, c;
  v.resize(n);
  c.resize(n);

  for(int i = 0; i < m; i++) {
    int t, f, d;
    cin >> t >> f >> d;
    t--;
    f--;
    v[t].push_back(f);
    v[f].push_back(t);
    c[t].push_back(d);
    c[f].push_back(d);
  }
  vector<bool> b;
  int ans = MAX_COST;
  for(int i = 0; i < n; i++) {
    b.clear();
    b.resize(n);
    multiset<N> q;
    q.insert(N(i, 0));
    int cnt = n;
    int maxcost = 0;
    while(q.size() > 0) {
      N node = *q.begin();
      q.erase(q.begin());
      if(b[node.now]) continue;
      b[node.now] = true;
      cnt--;
      maxcost = max(maxcost, node.d);
      if(cnt == 0) {
        ans = min(ans, maxcost);
        break;
      }
      for(int j = 0; j < v[node.now].size(); j++) {
        if(b[v[node.now][j]]) continue;
        q.insert(N(v[node.now][j], node.d + c[node.now][j]));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
