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

struct N {
  int now, mode;
};
bool operator<(const N &l, const N &r) { return l.now < r.now; }

int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  vector<set<int>> s(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  set<int> o, e;
  multiset<N> q;
  vector<int> c(n);
  q.insert(N{0, 1});
  while (q.size() > 0) {
    N now = *q.begin();
    q.erase(q.begin());
    if (c[now.now]) {
      if (c[now.now] != now.mode) {
        cout << n * (n - 1) / 2 - m << endl;
        return 0;
      }
      continue;
    }
    c[now.now] = now.mode;
    if (now.mode == 1)
      o.insert(now.now);
    else
      e.insert(now.now);
    for (int i = 0; i < p[now.now].size(); i++) {
      q.insert(N{p[now.now][i], 2 - (now.mode - 1)});
    }
  }
  long long os = o.size(), es = e.size();
  cout << os * es - m << endl;
  return 0;
}
