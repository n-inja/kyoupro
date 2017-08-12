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

#define P 1000000007

using namespace std;

class Union {
public:
  vector<int> parent;
  int n;
  Union(int _) {
    n = _;
    parent.resize(n);
    for(int i = 0; i < n; i++) parent[i] = i;
  }
  void link(int i, int j) {
    if(j < i) swap(i, j);
    int ip = i, jp = j;
    for(; ip != parent[ip]; ip = parent[ip]);
    for(; jp != parent[jp]; jp = parent[jp]);
    int par = min(ip, jp);

    for(ip = i; ip != parent[ip]; ) {
      int p = parent[ip];
      parent[ip] = par;
      ip = p;
    }
    for(jp = j; jp != parent[jp]; ) {
      int p = parent[jp];
      parent[jp] = par;
      jp = p;
    }
    parent[i] = par;
    parent[j] = par;
  }
  bool isLink(int i, int j) {
    if(j < i) swap(i, j);
    int ip = i, jp = j;
    for(; ip != parent[ip]; ip = parent[ip]);
    for(; jp != parent[jp]; jp = parent[jp]);
    return parent[ip] == parent[jp];
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  Union u(n);
  for(int i = 0; i < q; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    if(p == 0) u.link(a, b);
    else cout << (u.isLink(a, b) ? "Yes" : "No") << endl;
  }
  return 0;
}
