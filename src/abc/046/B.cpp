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
  ll n, k;
  cin >> n >> k;
  ll ans = k;
  for (int i = 0; i < n - 1; i++) ans *= (k - 1);
  cout << ans << endl;
  return 0;
}
