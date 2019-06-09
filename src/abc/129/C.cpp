#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll P = 1000000007;
ll dp[101010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> a(m);
  set<ll> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (s.find(i) != s.end()) continue;
    dp[i + 1] += dp[i];
    dp[i + 1] %= P;
    dp[i + 2] += dp[i];
    dp[i + 2] %= P;
  }
  cout << dp[n] << endl;
  return 0;
}
