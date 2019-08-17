#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int i;
  ll v;
};

bool operator<(const N &l, const N &r) {
  return l.v < r.v;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  priority_queue<N> q;
  for (int i = 0; i < n; i++) {
    if (b[i] > a[i])
      q.push(N{i, b[i]});
    else if (b[i] < a[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  ll ans = 0;
  while (q.size()) {
    auto now = q.top();
    q.pop();
    ll side = b[(now.i + n - 1) % n] + b[(now.i + 1) % n];
    if (side == 0 || now.v - side < a[now.i]) {
      cout << -1 << endl;
      return 0;
    }
    ll skip = (now.v - side) / side;
    if (skip == 0) skip++;
    skip = min(skip, (now.v - a[now.i] + side - 1) / side);
    b[now.i] -= skip * side;
    if (b[now.i] > a[now.i]) {
      q.push(N{now.i, b[now.i]});
    }
    ans += skip;
  }
  cout << ans << endl;

  return 0;
}
