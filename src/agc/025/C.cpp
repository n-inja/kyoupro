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
  vll l(n), r(n), lsum(n + 1), rsum(n + 1);
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  reverse(l.begin(), l.end());

  ll ans = 0;
  for (int i = 0; i < n; i++)
    lsum[i + 1] += lsum[i] + l[i];
  for (int i = 0; i < n; i++)
    rsum[i + 1] += rsum[i] + r[i];
  ans = max(ans, 0LL);
  for (int i = 0; i < (n + 1) / 2; i++) {
    ans = max(ans, 2 * (lsum[i + 1] - rsum[i + 1]));
    ans = max(ans, 2 * (lsum[i + 1] - rsum[i]));
    if (i < n / 2) {
      ans = max(ans, 2 * (lsum[i] - rsum[i + 1]));
    }
  }
  cout << ans << endl;
  return 0;
}
