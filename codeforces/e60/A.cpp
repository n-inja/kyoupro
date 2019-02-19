#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll maxa = a[0];
  for (int i = 1; i < n; i++)
    maxa = max(maxa, a[i]);
  ll ans = 0, now = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == maxa) {
      if (ok) {
        now++;
        ans = max(ans, now);
      } else {
        ok = true;
        now = 1;
        ans = max(ans, now);
      }
    } else {
      ok = false;
      now = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
