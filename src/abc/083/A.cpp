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
  if (a + b > c + d) cout << "Left" << endl;
  else if (a + b == c + d) cout << "Balanced" << endl;
  else cout << "Right" << endl;
  return 0;
}
