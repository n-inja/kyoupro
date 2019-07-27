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
  int n;
  cin >> n;
  vector<string> mp(n);
  for (int i = 0; i < n; i++) cin >> mp[i];
  ll a = 0, b = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (mp[i][j] == 'R') a++; else if (mp[i][j] == 'B') b++;
  if (a > b) cout << "TAKAHASHI" << endl;
  else if (a == b) cout << "DRAW" << endl;
  else cout << "AOKI" << endl;

  return 0;
}
