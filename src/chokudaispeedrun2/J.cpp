#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll dp[505050][2] = {0};
ll ab[505050][2];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ab[i][0] >> ab[i][1];
  dp[0][0] = ab[0][0];
  dp[0][1] = ab[0][1];
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(__gcd(dp[i - 1][0], ab[i][0]), __gcd(dp[i - 1][1], ab[i][0]));
    dp[i][1] = max(__gcd(dp[i - 1][0], ab[i][1]), __gcd(dp[i - 1][1], ab[i][1]));
  }
  cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

  return 0;
}
