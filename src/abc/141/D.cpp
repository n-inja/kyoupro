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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  priority_queue<ll> q;
  for (int i = 0; i < n; i++) q.push(a[i]);
  while (m) {
    auto v = q.top();
    q.pop();
    q.push(v / 2);
    m--;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
  return 0;
}
