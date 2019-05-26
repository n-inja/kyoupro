#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n, k;
vector<ll> v;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  ll ans = 0;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= i; j++) {
      // i回取り k - i回戻し
      // j回右から i - j回左から
      int li = -1, ri = n - 1;
      vector<ll> minus, plus;
      for (int k = 0; k < min(j, n); k++) {
        if (v[k] >= 0) plus.push_back(v[k]);
        else minus.push_back(v[k]);
        li = k;
      }
      for (int k = 0; k < i - j; k++) {
        int k2 = n - 1 - k;
        if (k2 <= li) continue;
        if (k2 < 0) continue;
        if (v[k2] >= 0) plus.push_back(v[k2]);
        else minus.push_back(v[k2]);
      }
      sort(minus.begin(), minus.end());
      ll sum = 0;
      for (auto &v : plus) sum += v;
      for (auto &v : minus) sum += v;
      for (int l = 0; l < min(k - i, (int) minus.size()); l++) sum -= minus[l];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
