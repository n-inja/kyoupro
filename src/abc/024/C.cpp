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
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> l(d), r(d), s(k), t(k);
  for (int i = 0; i < d; i++) cin >> l[i] >> r[i];
  for (int i = 0; i < k; i++) cin >> s[i] >> t[i];
  map<int, int> mp;
  for (int i = 0; i < k; i++) mp[s[i]] = 0, mp[t[i]] = 0;
  for (int i = 0; i < d; i++) mp[l[i]] = 0, mp[r[i]] = 0;
  int c = 0;
  for (auto &v : mp) {
    v.second = c++;
  }
  vector<int> ans(k, d);
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < k; j++) {
      if (s[j] < t[j]) {
        if (mp[l[i]] <= mp[s[j]] && mp[s[j]] < mp[r[i]]) {
          s[j] = r[i];
          if (s[j] >= t[j]) {
            ans[j] = min(ans[j], i + 1);
          }
        }
      } else {
        if (mp[l[i]] < mp[s[j]] && mp[s[j]] <= mp[r[i]]) {
          s[j] = l[i];
          if (s[j] <= t[j]) {
            ans[j] = min(ans[j], i + 1);
          }
        }
      }
    }
  }
  for (auto &i : ans) cout << i << endl;
  return 0;
}
