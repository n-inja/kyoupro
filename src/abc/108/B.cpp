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
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int vx = x2 - x1, vy = y2 - y1;
  int vx2 = -vy, vy2 = vx;
  int vx3 = -vx, vy3 = -vy;
  cout << x2 + vx2 << " " << y2 + vy2 << " " << x2 + vx2 + vx3 << " " << y2 + vy2 + vy3 << endl;

  return 0;
}
