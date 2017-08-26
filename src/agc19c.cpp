#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

const long long PRIME = 1000000007;
const double mpi = 3.14159265358979323846;

using namespace std;

struct segtree {
    int N, dat[800001];
    segtree() {}
    segtree(int n) {
        N = 1;
        while(N < n) N *= 2;
        for(int i = 0; i < 2*N-1; i++)
            dat[i] = 0;
    }
    // update k th element
    void update(int k, int a) {
        k += N-1; // leaf
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // min [a, b)
    int query(int a, int b) { return query(a, b, 0, 0, N); }
    int query(int a, int b, int k, int l, int r) {
        if(r <= a or b <= l) return 0;
        if(a <= l and r <= b) return dat[k];
        int m = (l + r) / 2;
        return min(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
    }
};

class Tate {
public:
  long long x, y;
  Tate(long long _, long long __) {
    x = _;
    y = __;
  }
  bool operator<(const Tate &rhs) const {
    return this->x < rhs.x;
  }
  bool operator>(const Tate &rhs) const {
    return this->x > rhs.x;
  }
};

class Yoko {
public:
  int i;
  long long x, y;
  Yoko(long long _, long long __, int id) {
    x = _;
    y = __;
    i = id;
  }
  bool operator<(const Yoko &rhs) const {
    return this->y < rhs.y;
  }
  bool operator>(const Yoko &rhs) const {
    return this->y > rhs.y;
  }
};

int main() {
  pair<long long, long long> s, e;
  cin >> s.first >> s.second >> e.first >> e.second;
  int n;
  cin >> n;
  vector<pair<long long, long long>> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  if(s.first > e.first) {
    s.first = -s.first;
    e.first = -e.first;
    for(int i = 0; i < n; i++) p[i].first = -p[i].first;
  }
  if(s.second > e.second) {
    s.second = -s.second;
    e.second = -e.second;
    for(int i = 0; i < n; i++) p[i].second = -p[i].second;
  }
  vector<pair<long long, long long>> fp;
  for(int i = 0; i < n; i++) {
    if(s.first <= p[i].first && p[i].first <= e.first && s.second <= p[i].second && p[i].second <= e.second ) {
      fp.push_back(p[i]);
    }
  }
  int m = fp.size();
  vector<Tate> t;
  for(int i = 0; i < m; i++) {
    t.push_back(Tate(fp[i].first, fp[i].second));
  }
  sort(t.begin(), t.end());
  vector<Yoko> y;
  for(int i = 0; i < m; i++) {
    y.push_back(Yoko(t[i].x, t[i].y, i));
  }
  sort(y.begin(), y.end());
  segtree seg(m);
  for(int i = 0; i < m; i++) {
    int mi = seg.query(0, y[i].i);
    seg.update(y[i].i, mi - 1);
  }
  int cnt = -seg.query(0, m);
  double ans = (e.first - s.first + e.second - s.second) * 100;
  if(cnt - 1 == min(e.first - s.first, e.second - s.second)) {
    ans -= 20 * cnt;
    ans += 10 * mpi;
    ans += 5 * mpi * (cnt - 1);
  } else {
    ans -= 20 * cnt;
    ans += 5 * mpi * cnt;
  }
  printf("%.15lf\n", ans);

  return 0;
}
