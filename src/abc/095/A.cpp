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
  ll ans = 700;
  for (int i = 0; i < 3; i++) {
    char c;
    cin >> c;
    if (c == 'o') ans += 100;
  }
  cout << ans << endl;
  return 0;
}
