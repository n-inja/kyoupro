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
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  auto q = p;
  sort(q.begin(), q.end());
  int d = 0;
  for (int i = 0; i < n; i++) if (p[i] != q[i]) d++;
  if (d <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
