#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

long long INF = 100000000000000000LL;
static const int MAX_SIZE =
    1 << 18; // segment tree のサイズ。この実装では2べきにする必要がある。
             // 2^17 ≒ 1.3 * 10^5

typedef long long ll;
ll segMin[2 * MAX_SIZE - 1] = {0}, segAdd[2 * MAX_SIZE - 1] = {0};

//区間[a, b)に値xを加算する.
void add(int a, int b, ll x, int k = 0, int l = 0, int r = MAX_SIZE) {
  if (r <= a || b <= l)
    return; //もし交差しない区間であれば終える.

  if (a <= l &&
      r <= b) { //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
    segAdd[k] += x; //区間[l, r)にkを加算する.
    return;
  }

  add(a, b, x, k * 2 + 1, l,
      (l + r) / 2); //子の区間に(必要があれば)xを加算する.
  add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃

  //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値
  //である.一様に加算される値は更新しなくて良い.
  segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1],
                  segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

ll getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE) {
  if (r <= a || b <= l)
    return (INF);

  if (a <= l && r <= b)
    return (segMin[k] +
            segAdd[k]); //完全に内包されていれば,その区間の最小値を返す.

  ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
  ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める

  return (min(left, right) + segAdd[k]); //親の区間の最小値は, 子の区間の最小値
                                         //+ 自分に一様に加算されている値 である
                                         //(大切なので2回書きました!!)
}
// ref: http://kagamiz.hatenablog.com/entry/2012/12/18/220849

struct N {
  int l, r;
  long long a;
};

int main() {
  int n, m;
  cin >> m >> n;

  vector<N> ns(n);
  for (int i = 0; i < n; i++)
    cin >> ns[i].l >> ns[i].r >> ns[i].a;
  map<int, vector<N>> rmp, lmp;
  for (int i = 0; i < n; i++) {
    rmp[ns[i].r].push_back(ns[i]);
    lmp[ns[i].l].push_back(ns[i]);
    add(ns[i].l, ns[i].r + 1, ns[i].a);
  }
  long long ans = 0;
  long long sum = 0;
  long long tmp;
  for (int i = 1; i <= m; i++) {
    if (lmp.find(i) != lmp.end()) {
      for (auto &s : lmp[i])
        sum += s.a;
    }
    tmp = -getMin(0, i) + sum;
    ans = max(ans, tmp);
    add(i, i + 1, -tmp);
    if (rmp.find(i) != rmp.end()) {
      for (auto &s : rmp[i]) {
        sum -= s.a;
        add(s.l, s.r + 1, -s.a);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
