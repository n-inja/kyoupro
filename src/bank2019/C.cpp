#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool dp[201010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int x;
  cin >> x;
  dp[0] = true;
  vector<int> v({100, 101, 102, 103, 104, 105});
  int n = 6;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x; j++) dp[j + v[i]] |= dp[j];
  }
  cout << dp[x] << endl;
  return 0;
}
