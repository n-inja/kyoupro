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
  ll a, b, x;
  cin >> a >> b >> x;
  if (a == 0) {
    cout << b / x + 1 << endl;
    return 0;
  }
  a--;
  cout << b / x - a / x << endl;
  return 0;
}
