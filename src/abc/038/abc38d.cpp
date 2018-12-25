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

using namespace std;

struct segtree {
  int N, dat[800001];
  segtree() {}
  segtree(int n) {
    N = 1;
    while(N < n) N *= 2;
    for(int i = 0; i < 2*N-1; i++) dat[i] = 0;
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

typedef struct {
  long long h, w;
} A;

bool operator<(const A &lhs, const A &rhs) {
  return lhs.h * 1000001 + (1000000 - lhs.w) < rhs.h * 1000001 + (1000000 - rhs.w);
}

bool operator>(const A &lhs, const A &rhs) {
  return lhs.h * 1000001 + (1000000 - lhs.w) > rhs.h * 1000001 + (1000000 - rhs.w);
}

int main() {
  int n;
  cin >> n;
  vector<A> v(n);
  map<long long, bool> mp;
  for(int i = 0; i < n; i++) {
    cin >> v[i].h >> v[i].w;
    if(mp[v[i].h * 1000000 + (1000000 - v[i].w)]) {
      v[i].h = 1000001;
      v[i].w = 1000001;
    } else {
      mp[v[i].h * 1000000 + (1000000 - v[i].w)] = false;
    }
  }
  sort(v.begin(), v.end());
  segtree s(100000);
  for(int i = 0; i < n; i++) {
    if(v[i].h > 100000) break;
    int m = s.query(0, v[i].w);
    s.update(v[i].w, m - 1);
  }
  cout << -s.query(0, 100001) << endl;
  return 0;
}
