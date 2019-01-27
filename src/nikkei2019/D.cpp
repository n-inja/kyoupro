#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
int n, m;
vector<vector<int>> p, inv;
vector<int> ans;
vector<int> dep;

int dfs(int i) {
  if (dep[i] >= 0)
    return dep[i];
  int par = 0;
  int now = -1;
  for (int &j : p[i]) {
    int d = dfs(j);
    if (now < d) {
      now = d;
      par = j;
    }
  }
  dep[i] = now + 1;
  ans[i] = par + 1;
  return dep[i];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  p.resize(n);
  inv.resize(n);
  for (int i = 0; i < n + m - 1; i++) {
    int t, f;
    cin >> f >> t;
    t--;
    f--;
    inv[f].push_back(t);
    p[t].push_back(f);
  }
  ans.resize(n);
  dep.resize(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (p[i].size() == 0) {
      ans[i] = 0;
      dep[i] = 0;
      root = i;
    } else {
      ans[i] = -1;
      dep[i] = -1;
    }
  }

  for (int i = 0; i < n; i++)
    dfs(i);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
