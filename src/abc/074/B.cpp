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
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += min(x, k - x) * 2;
  }
  cout << ans << endl;
  return 0;
}
