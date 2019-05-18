#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  int cnt[26] = {0};
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i][0] - 'a']++;
  }
  ll ans = 0;
  for (int i = 0; i < 26; i++) {
    int m = 10000000;
    for (int j = 0; j < cnt[i]; j++) {
      int k = cnt[i] - j;
      m = min(m, k * (k - 1) / 2 + j * (j - 1) / 2);
    }
    if (m < 10000000)
      ans += m;
  }
  cout << ans << endl;
  return 0;
}
