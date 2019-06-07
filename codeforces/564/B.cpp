#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int n;
ll P = 998244353;
ll fac[201010] = {0};
vector<vector<int>> p;

ll dfs(int i, int from) {
  ll ret = 1;
  int c = 1;
  if (from < 0) c = 0;
  for (auto &j: p[i]) {
    if (j == from) continue;
    c++;
    ret *= dfs(j, i);
    ret %= P;
  }
  ret *= fac[c];
  ret %= P;


  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  p.resize(n);
  fac[0] = 1;
  for (int i = 0; i <= n; i++) {
    fac[i + 1] = (i + 1) * fac[i];
    fac[i + 1] %= P;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }

  cout << (dfs(0, -1) * n) % P << endl;

  return 0;
}
