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
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += max(0, 80 - a);
  }
  cout << ans << endl;
  return 0;
}
