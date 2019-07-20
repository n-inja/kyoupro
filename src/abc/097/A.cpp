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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
