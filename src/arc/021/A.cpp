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
  vector<vector<int>> a(4, vector<int>(4));
  for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) cin >> a[i][j];
  bool ok = false;
  for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) if (a[i][j] == a[i + 1][j]) ok = true;
  for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) if (a[i][j] == a[i][j + 1]) ok = true;
  if (ok) cout << "CONTINUE" << endl;
  else cout << "GAMEOVER" << endl;
  return 0;
}
