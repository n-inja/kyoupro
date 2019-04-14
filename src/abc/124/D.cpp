#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vll v;
  int c = 0;
  char now = '1';
  for (int i = 0; i < n; i++) {
    if (now == s[i]) {
      c++;
    } else {
      v.push_back(c);
      c = 1;
      now = s[i];
    }
  }
  v.push_back(c);
  v.push_back(0);
  ll sum = 0;

  ll m = v.size();
  for (int i = 0; i < 2 * k + 1 && i < m; i++) {
    sum += v[i];
  }
  ll ans = sum;
  for (int j = 0; j < m - 2 * k - 1; j++) {
    sum -= v[j];
    sum += v[j + 2 * k + 1];
    if (j % 2 == 1)
      ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
