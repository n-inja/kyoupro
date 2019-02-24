#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll ans = 1000000000000LL;
int n, a[3];
vll l;

void f(vector<int> &v) {
  ll sub = 0;
  ll cnt[4] = {0}, b[4] = {0};
  for (int i = 0; i < n; i++) {
    cnt[v[i]]++;
    b[v[i]] += l[i];
  }
  for (int i = 0; i < 3; i++) {
    if (cnt[i] == 0)
      return;
    sub += (cnt[i] - 1) * 10;
    sub += abs(a[i] - b[i]);
  }
  ans = min(ans, sub);
}

void dfs(int i, vector<int> &v) {
  if (i == n) {
    f(v);
    return;
  }
  for (int j = 0; j < 4; j++) {
    v[i] = j;
    dfs(i + 1, v);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> a[0] >> a[1] >> a[2];
  l.resize(n);
  for (int i = 0; i < n; i++)
    cin >> l[i];
  vector<int> v(n);
  dfs(0, v);
  cout << ans << endl;
  return 0;
}
