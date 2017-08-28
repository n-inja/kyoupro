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

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  void add(int a, int w) {
    if(a == 0 || a > n) return;
    for(int x = a; x <= n; x += x & -x) bit[x] += w;
  }
  int sum(int a) {
    if(a == 0) return 0;
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
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
  vector<int> v(n);
  vector<N> node;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    node.push_back(N(v[i], i));
  }
  sort(node.begin(), node.end());

  vector<int> id(n);
  for(int i = 0; i < n; i++) id[node[i].id] = i;

  BIT bit(n);
  long long ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    ans += bit.sum(id[i]);
    bit.add(id[i] + 1, 1);
  }
  cout << ans << endl;
  return 0;
}
