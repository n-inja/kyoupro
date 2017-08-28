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

class N {
public:
  int val, id;
  N(int _, int __) {
    val = _;
    id = __;
  }
  bool operator>(const N &rhs) const {
    return this->val > rhs.val;
  }
  bool operator<(const N &rhs) const {
    return this->val < rhs.val;
  }
};

int main() {
  int n;
  cin >> n;
  segtree s(n);
  vector<int> v(n);
  vector<N> node;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    node.push_back(N(v[i], i));
  }
  sort(node.begin(), node.end());
  for(int i = 0; i < n; i++) {
    int mi = s.query(0, node[i].id);
    s.update(node[i].id, mi - 1);
  }
  cout << -s.query(0, n) << endl;
  return 0;
}
