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
  int a, b, k;
  cin >> a >> b >> k;
  if (b >= k) cout << a + k << endl;
  else cout << b + (a - (k - b)) << endl;

  return 0;
}
