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
  ll n;
  cin >> n;
  ll P = 1000000007;
  ll ans = 1;
  for (int i = 0; i < n; i++) ans = (ans * (i + 1)) % P;
  cout << ans << endl;
  return 0;
}
