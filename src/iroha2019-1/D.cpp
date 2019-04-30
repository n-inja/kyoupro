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
  ll x, y, n;
  cin >> n >> x >> y;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
      x += a[i];
    else
      y += a[i];
  cerr << x << " " << y << endl;
  if (x == y)
    cout << "Draw" << endl;
  else if (x > y)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}
