#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct N {
  int i, a, c;
};
bool operator<(const N &l, const N &r) { return l.a < r.a; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<N> ns(n);
  for (int i = 0; i < n; i++) {
    cin >> ns[i].a;
    ns[i].i = i;
    ns[i].c = 0;
  }
  vi ans(n);
  sort(ns.begin(), ns.end());
  map<int, int> mp;
  bool ok = true;
  int bef = 0;
  for (int i = 0; i < n; i++) {
    mp[ns[i].a]++;
    if (mp[ns[i].a] > k)
      ok = false;
    bef = ans[ns[i].i] = (bef + 1) % k;
  }
  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << ans[0] + 1;
    for (int i = 1; i < n; i++)
      cout << " " << ans[i] + 1;
    cout << endl;
  }
  return 0;
}
