#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vi a(5);
  for (int i = 0; i < 5; i++)
    cin >> a[i];
  int ans = 0, r = 10;
  for (int i = 0; i < 5; i++) {
    ans += 10 * ((a[i] + 9) / 10);
    int l = a[i] % 10;
    if (a[i] % 10 == 0)
      l += 10;
    r = min(r, l);
  }
  cout << ans - 10 + r << endl;
  return 0;
}
