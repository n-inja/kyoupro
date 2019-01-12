#include <bits/stdc++.h>

using namespace std;

struct N {
  int l, r, i, ans;
};
bool operator<(const N &l, const N &r) { return l.l < r.l; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<N> ns(n);
    for (int i = 0; i < n; i++) {
      cin >> ns[i].l >> ns[i].r;
      ns[i].i = i;
    }
    sort(ns.begin(), ns.end());
    bool ok = false;
    int r = ns[0].r;
    ns[0].ans = 0;
    for (int i = 1; i < n; i++) {
      if (r >= ns[i].l) {
        r = max(r, ns[i].r);
        ns[i].ans = ns[i - 1].ans;
      } else {
        ok = true;
        r = ns[i].r;
        ns[i].ans = 1 - ns[i - 1].ans;
      }
    }
    if (ok) {
      vector<int> ans(n);
      for (int i = 0; i < n; i++)
        ans[ns[i].i] = ns[i].ans + 1;
      cout << ans[0];
      for (int i = 1; i < n; i++) {
        cout << " " << ans[i];
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
