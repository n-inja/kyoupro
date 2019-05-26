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
  int a, b;
  cin >> a >> b;
  if (a <= 5) cout << 0 << endl;
  else if (a <= 12) cout << b / 2 << endl;
  else cout << b << endl;
  return 0;
}
