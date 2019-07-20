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
  int x;
  cin >> x;
  int ans = 1;
  for (int i = 2; i <= x; i++) {
    for (int j = i * i; j <= x; j *= i) {
      ans = max(ans, j);
    }
  }
  cout << ans << endl;
  return 0;
}
