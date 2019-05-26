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
  ll r, d, x;
  cin >> r >> d >> x;
  for (int i = 0; i < 10; i++) {
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}
