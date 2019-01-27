#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct N {
  ll a, b, c;
};
bool operator<(const N &l, const N &r) { return l.c > r.c; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<N> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i].a >> c[i].b;
    c[i].c = c[i].a + c[i].b;
  }
  sort(c.begin(), c.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      ans += c[i].a;
    else
      ans -= c[i].b;
  }
  cout << ans << endl;
  return 0;
}
