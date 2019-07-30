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
  vector<pair<long long, int>> v;
  long long quey;

  Bucket(int n) {
    size = n;
    v.resize(n);
    for (int i = 0; i < n; i++) v[i].second = i;
    quey = 0;
  }

  void change(ll q) {
    quey = max(quey, q);
  }

  void set(int j, ll b) {
    if (quey) {
      for (int i = 0; i < size; i++) v[i].first = max(v[i].first, quey);
      quey = 0;
    }
    v[j].first = b;
  }

  long long get(int i) {
    if (quey) {
      for (int i = 0; i < size; i++) v[i].first = max(v[i].first, quey);
      quey = 0;
    }
    return v[i].first;
  }
};

const int BSIZE = 450;

class Buckets {
public:
  vector<Bucket> b;
  int size;
  int bsize;
  int num;

  Buckets(int n) {
    size = n;
    bsize = (n + BSIZE - 1) / BSIZE;
    for (; n > 0; n -= bsize) {
      Bucket c(min(n, bsize));
      b.push_back(c);
    }
    num = b.size();
  }

  void change(ll c) {
    for (int i = 0; i < num; i++) b[i].change(c);
  }

  void set(int i, ll c) {
    b[i / bsize].set(i - (i / bsize) * bsize, c);
  }

  long long get(int i) { return b[i / bsize].get(i - (i / bsize) * bsize); }
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Buckets b(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    b.set(i, a);
  }
  ll q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      int j;
      ll x;
      cin >> j >> x;
      b.set(j - 1, x);
    } else {
      ll x;
      cin >> x;
      b.change(x);
    }
  }
  cout << b.get(0);
  for (int i = 1; i < n; i++) {
    cout << " " << b.get(i);
  }
  cout << endl;

  return 0;
}
