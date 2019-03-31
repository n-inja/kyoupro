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
 
using namespace std;

int n, m;

int p2x(int id) {
  return id % m;
}

int p2y(int id) {
  return id / m;
}

struct A {
  int id;
  long long val;
};

bool operator<(const A &lhs, const A &rhs) {
  return lhs.val < rhs.val;
}

int main() {
  long long x, a, p;
  cin >> n >> m >> x >> a >> p;
  vector<A> prs(n * m);
  prs[0].val = x;
  for(int i = 1; i < n * m; i++) prs[i].val = (prs[i - 1].val + a) % p;
  for(int i = 0; i < n * m; i++) prs[i].id = i;
  sort(prs.begin(), prs.end());
  for(int i = 1; i < n * m; i++) if(prs[i - 1].val == prs[i].val) {
    if(x < p) cout << 0 << endl;
    else {
      cout << (n - 1) * 2 << endl;
    }
    return 0;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) ans += abs(p2y(prs[i * m + j].id) - i);
    multiset<int> xs;
    vector<bool> b(m);
    for(int j = 0; j < m; j++) {
      if(b[p2x(prs[i * m + j].id)]) {
        xs.insert(p2x(prs[i * m + j].id));
      } else {
        b[p2x(prs[i * m + j].id)] = true;
      }
    }
    auto it = xs.begin();
    for(int j = 0; j < m; j++) {
      if(!b[j]) {
        ans += abs(j - *it);
        it++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}