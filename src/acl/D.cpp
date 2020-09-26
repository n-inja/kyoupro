#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using LL = long long;
using vi = vector<int>;
LL INF = 100000000000LL;

// https://scrapbox.io/ganariya/%E9%81%85%E5%BB%B6%E8%A9%95%E4%BE%A1%E3%82%BB%E3%82%B0%E3%83%A1%E3%83%B3%E3%83%88%E6%9C%A8%E3%80%80%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA
struct LazySegmentTree {
private:
  LL n;
  vector<LL> node, lazy;
  vector<bool> lazyFlag;

public:
  LazySegmentTree(vector<LL> v) {
    LL sz = (LL) v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1, INF);
    lazyFlag.resize(2 * n - 1, false);

    for (LL i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (LL i = n - 2; i >= 0; i--) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
  }

  void lazyEvaluate(LL k, LL l, LL r) {
    if (lazyFlag[k]) {
      node[k] = min(node[k], lazy[k]);
      if (r - l > 1) {
        lazy[k * 2 + 1] = min(lazy[k * 2 + 1], lazy[k]);
        lazy[k * 2 + 2] = min(lazy[k * 2 + 2], lazy[k]);
        lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
      }
      lazyFlag[k] = false;
    }
  }

  void update(LL a, LL b, LL x, LL k = 0, LL l = 0, LL r = -1) {
    if (r < 0) r = n;
    lazyEvaluate(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = min(lazy[k], x);
      lazyFlag[k] = true;
      lazyEvaluate(k, l, r);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = min(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  LL find(LL a, LL b, LL k = 0, LL l = 0, LL r = -1) {
    if (r < 0) r = n;
    lazyEvaluate(k, l, r);
    if (b <= l || r <= a) return INF;
    if (a <= l && r <= b) return node[k];
    LL vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
    LL vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  LazySegmentTree lr(vector<ll>(1 << 20, 0));
  for (int i = 0; i < n; i++) {
    ll l = max(0LL, a[i] - k), r = a[i] + k + 1;
    ll v = lr.find(l, r);
    lr.update(a[i], a[i] + 1, v - 1);
  }
  cout << -lr.find(0, 300001) << endl;
  return 0;
}
