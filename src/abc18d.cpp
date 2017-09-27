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

int n, m, p, q, r, ans = 0;
vector<vector<pair<int, int>>> path;

void dfs(int remain, long long dt, int maxid) {
  if(remain > 0) {
    for(int i = maxid + 1; i < n - remain + 1; i++) {
      dfs(remain - 1, dt | (1 << i), i);
    }
  } else {
    vector<int> s(m);
    for(int i = 0; i < 18; i++) if((dt & (1 << i)) > 0) for(int j = 0; j < path[i].size(); j++) s[path[i][j].first] -= path[i][j].second;
    sort(s.begin(), s.end());
    int sum = 0;
    for(int i = 0; i < q; i++) sum -= s[i];
    ans = max(ans, sum);
  }
}

int main() {
  cin >> n >> m >> p >> q >> r;
  path.resize(n);
  for(int i = 0; i < r; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    path[x].push_back(make_pair(y, z));
  }
  dfs(p, 0, -1);
  cout << ans << endl;
  return 0;
}
