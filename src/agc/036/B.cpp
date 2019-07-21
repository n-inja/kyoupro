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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> nextk(n + 1, vector<int>(21));
  for (int i = 0; i < n + 1; i++) nextk[i][0] = i;
  map<ll, int> bef;
  map<ll, int> first;
  for (int i = 0; i < n; i++) {
    if (bef.find(a[i]) == bef.end()) {
      first[a[i]] = i;
      bef[a[i]] = i;
    } else {
      nextk[bef[a[i]]][0] = i + 1;
      bef[a[i]] = i;
    }
  }

  for (int k = 1; k <= 20; k++) {
    for (int i = 0; i < n + 1; i++) {
      nextk[i][k] = nextk[nextk[i][k - 1]][k - 1];
    }
  }

  vector<ll> c;
  c.push_back(0);
  ll now = 0;
  while (now < n && nextk[now][20] < n) {
    ll v = a[nextk[now][20]];
    c.push_back(v);
    now = first[v] + 1;
  }

  k--;
  int p = c[k % c.size()];

  first[0] = -1;
  vector<int> ans;
  vector<bool> used(202020);
  for (int i = first[p] + 1; i < n; i++) {
    if (used[a[i]]) {
      while (a[i] != ans.back()) {
        used[ans.back()] = false;
        ans.pop_back();
      }
      used[ans.back()] = false;
      ans.pop_back();
    } else {
      ans.push_back(a[i]);
      used[a[i]] = true;
    }
  }

  if (ans.size() == 0) {
    return 0;
  }

  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
  cout << endl;

  return 0;
}
