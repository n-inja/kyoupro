#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll INF = (1LL << 62);

bool can(ll bit) { return bit < INF; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  set<int> s;
  for (int i = 0; i < 50; i++)
    s.insert(i + 1);
  ll ans = INF;
  for (int loop = 50; loop >= 0; loop--) {
    ll p[51][51];
    for (int i = 0; i <= 50; i++)
      for (int j = 0; j <= 50; j++)
        p[i][j] = INF;
    for (int i = 0; i <= 50; i++) {
      for (int j = 0; j < i; j++)
        for (auto &k : s) {
          if (i % k == j)
            p[i][j] = min(p[i][j], 1LL << k);
        }
      p[i][i] = 0;
    }
    for (int k = 0; k <= 50; k++) {
      for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
          p[i][j] = min(p[i][j], p[i][k] | p[k][j]);
        }
      }
    }
    ll subans = 0;
    for (int i = 0; i < n; i++)
      subans |= p[a[i]][b[i]];
    if (!can(subans)) {
      if (loop == 50) {
        cout << -1 << endl;
        return 0;
      } else {
        s.insert(loop + 1);
      }
    }
    ans = min(ans, subans);

    s.erase(loop);
  }
  cout << ans << endl;
  return 0;
}
