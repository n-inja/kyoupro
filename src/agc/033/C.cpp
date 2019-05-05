#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
vector<vector<int>> p;
vector<bool> used;
vector<int> dep;
void dfs(int i, int d) {
  if (used[i])
    return;
  used[i] = true;
  dep[i] = d;
  for (auto &j : p[i])
    dfs(j, d + 1);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  p.resize(n);
  used.resize(n);
  dep.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  dfs(0, 0);
  int l = 0;
  for (int i = 0; i < n; i++)
    if (dep[l] < dep[i])
      l = i;
  for (int i = 0; i < n; i++)
    used[i] = false;
  dfs(l, 0);
  int maxd = 0;
  for (int i = 0; i < n; i++)
    maxd = max(maxd, dep[i]);
  if (maxd % 3 == 1) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
  return 0;
}
