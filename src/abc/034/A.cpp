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
  int x, y;
  cin >> x >> y;
  if (y > x) cout << "Better" << endl;
  else cout << "Worse" << endl;
  return 0;
}
