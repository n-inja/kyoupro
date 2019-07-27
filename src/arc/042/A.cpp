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
  vector<int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  queue<int> q;
  for (int i = m - 1; i >= 0; i--) q.push(a[i]);
  for (int i = 1; i <= n; i++) q.push(i);
  vector<bool> used(n + 1);
  while (q.size()) {
    int t = q.front();
    q.pop();
    if (used[t]) continue;
    used[t] = true;
    cout << t << endl;
  }
  return 0;
}
