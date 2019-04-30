#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class Bucket {
public:
  int size;
  vector<long long> v, l, r, all;
  vvl q;
  Bucket(int n) {
    size = n;
    v.resize(n);
    l.resize(n + 1);
    r.resize(n + 1);
    q.resize(n);
    for (int i = 0; i < n; i++)
      q[i].resize(n);
  }
  void update() {
    l[0] = 0;
    for (int i = 0; i < size; i++)
      l[i + 1] = l[i] | v[i];
    r[size] = 0;
    for (int i = size - 1; i >= 0; i--)
      r[i] = r[i + 1] | v[i];
    reverse(r.begin(), r.end());
    for (int i = 0; i < size; i++) {
      q[i][i] = v[i];
      all.push_back(q[i][i]);
    }
    for (int i = 0; i < size; i++)
      for (int j = i + 1; j < size; j++) {
        q[i][j] = q[i][j - 1] | v[j];
        all.push_back(q[i][j]);
      }
    sort(all.begin(), all.end());
  }
  // >=kなる区間数
  long long query(ll k) {
    auto it = lower_bound(all.begin(), all.end(), k);
    return all.end() - it;
  }
  long long al() { return l[size]; }
  long long get(int i) { return v[i]; }
  void set(int i, ll a) { v[i] = a; }
};

const int SIZE = 300;
class Buckets {
public:
  vector<Bucket> b;
  int size;
  int bsize;
  int num;
  vvl q;
  Buckets(int n) {
    size = n;
    bsize = (n + SIZE - 1) / SIZE;
    for (; n > 0; n -= bsize) {
      Bucket c(min(bsize, n));
      b.push_back(c);
    }
    num = b.size();
    q.resize(num);
    for (int i = 0; i < num; i++) {
      q[i].resize(num);
    }
  }
  void update() {
    for (int i = 0; i < num; i++)
      b[i].update();
    for (int i = 0; i < num; i++)
      q[i][i] = b[i].al();
    for (int i = 0; i < num; i++) {
      for (int j = i + 1; j < num; j++)
        q[i][j] = q[i][j - 1] | b[j].al();
    }
  }
  long long query(ll k) {
    ll ans = 0;
    for (int i = 0; i < num; i++) {
      ans += b[i].query(k);
    }
    for (int i = 0; i < num; i++) {
      for (int j = i + 1; j < num; j++) {
        ll piv = 0;
        if (j - i > 1) {
          piv = q[i + 1][j - 1];
        }
        if (piv >= k) {
          ans += b[i].size * b[j].size;
          continue;
        }
        ll all = b[i].size * b[j].size;
        for (int ri = 1; ri <= b[i].size; ri++) {
          ll base = b[i].r[ri] | piv;
          ll l = 0, r = b[j].size;
          if (base >= k) {
            break;
          }
          if ((base | b[j].l[r]) < k) {
            all -= b[j].size;
            continue;
          }
          // [0, l) x < k
          // [0, r) x >= k
          while (r - l > 1) {
            ll m = (l + r) / 2;
            if ((base | b[j].l[m]) >= k) {
              r = m;
            } else {
              l = m;
            }
          }
          all -= l;
        }
        ans += all;
      }
    }
    return ans;
  }
  void set(int i, ll a) { b[i / bsize].set(i - (i / bsize) * bsize, a); }
  long long get(int i) { return b[i / bsize].get(i - (i / bsize) * bsize); }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  Buckets hex(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    hex.set(i, a);
  }
  hex.update();

  ll l = 0, r = (1LL << 60);
  while (r - l > 1) {
    ll m = (l + r) / 2;
    ll q = hex.query(m);
    if (q >= k) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
