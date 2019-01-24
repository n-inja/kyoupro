#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  using vpllll = vector<pair<ll, ll>>;
  vpllll vp(m);
  for (int i = 0; i < n; i++)
    add(i, i + 1, v[i]);
  vector<vector<int>> l(n), r(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> vp[i].first >> vp[i].second;
    int st = vp[i].first, nd = vp[i].second;
    vp[i].first--;
    vp[i].second--;
    st--;
    l[st].push_back(nd);
    r[nd].push_back(st);
    add(st, nd, -1);
  }
  ll ans = -1;
  int ansi = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l[i].size(); j++) {
      add(i, l[i][j], 1);
    }
    for (int j = 0; j < r[i].size(); j++) {
      add(r[i][j], i, -1);
    }
    if (ans < v[i] - getMin(0, n)) {
      ans = v[i] - getMin(0, n);
      ansi = i;
    }
  }
  cout << ans << endl;
  vector<int> anss;
  for (int i = 0; i < m; i++)
    if (!(vp[i].first <= ansi && ansi <= vp[i].second)) {
      anss.push_back(i + 1);
    }
  cout << anss.size() << endl;
  if (anss.size()) {
    cout << anss[0];
    for (int i = 1; i < anss.size(); i++)
      cout << " " << anss[i];
    cout << endl;
  }
  return 0;
}
