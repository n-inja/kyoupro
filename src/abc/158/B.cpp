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
  ll a, b, c, n;
  cin >> n >> a >> b;
  c = a + b;
  cout << (n / c) * a + min(n % c, a) << endl;
  return 0;
}
