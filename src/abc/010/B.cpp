#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int f(int a) {
  if (a == 0) return 0;
  if (a % 2 == 0) return 1 + f(a - 1);
  if (a % 3 == 2) return 1 + f(a - 1);
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int ans = 0;
  for (int i = 0; i < n; i++) ans += f(v[i]);
  cout << ans << endl;
  return 0;
}
