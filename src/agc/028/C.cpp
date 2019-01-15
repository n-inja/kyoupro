#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct N {
  int i;
  ll val;
  bool a;
};
bool operator<(const N &l, const N &r) { return l.val < r.val; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> v(n * 2);
  vll a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i * 2].val >> v[i * 2 + 1].val;
    a[i] = v[i * 2].val;
    b[i] = v[i * 2 + 1].val;
    v[i * 2].i = i;
    v[i * 2 + 1].i = i;
    v[i * 2].a = true;
    v[i * 2 + 1].a = false;
  }
  ll ans = 0;
  ll sa = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    sa += a[i];
    sb += b[i];
  }
  ans = min(sa, sb);
  vi count(n);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    count[v[i].i]++;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (count[i] == 2)
      ok = true;
  }
  if (ok) {
    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum += v[i].val;
    ans = min(ans, sum);
  } else {
    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum += v[i].val;
    for (int i = 0; i < n; i++) {
      ll sc = sum;
      if (count[i] > 0) {
        sc -= min(a[i], b[i]);
        int k = 0;
        while (true) {
          if (v[n + k].i != i) {
            sc += v[n + k].val;
            break;
          }
          k++;
        }
        ans = min(ans, sc);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
