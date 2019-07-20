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
  int n, s, t;
  cin >> s >> t >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < s) {
      cout << s - a << endl;
    } else if (a <= t) {
      cout << 0 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
