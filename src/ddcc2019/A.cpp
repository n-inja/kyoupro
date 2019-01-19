#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  double dp[201011];
  dp[0] = 0;
  for (int i = 0; i < 201010; i++) {
    dp[i + 1] = dp[i] + 1. / (i + 2);
  }
  int n;
  cin >> n;
  string s;
  cin >> s;
  vi v;
  bool b = false;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
      if (!b) {
        c++;
      } else {
        v.push_back(c);
        c = 1;
        b = false;
      }
    } else {
      if (b) {
        c++;
      } else {
        v.push_back(c);
        c = 1;
        b = true;
      }
    }
  }
  v.push_back(c);
  double sum = 0;
  int maxv = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i % 2 == 0) {
      sum += v[i];
    } else {
      sum += dp[v[i]];
      maxv = max(maxv, v[i]);
    }
  }
  printf("%.9lf\n", sum - dp[maxv] + dp[maxv + 1] - 1);

  return 0;
}
