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
  ll x, a, b;
  cin >> x >> a >> b;
  cout << x - a - ((x - a) / b * b) << endl;
  return 0;
}
