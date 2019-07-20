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
  if (a == 1) a += 13;
  if (b == 1) b += 13;
  if (a == b) cout << "Draw" << endl;
  else if (a < b) cout << "Bob" << endl;
  else cout << "Alice" << endl;
  return 0;
}
