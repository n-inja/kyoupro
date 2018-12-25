#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> p;

int main() {
  cin >> n >> m;
  p.resize(n);
  for (int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    p[t].push_back(f);
    p[f].push_back(t);
  }
  vector<int> ans(3 * n);
  set<int> as;
  int offset = n * 3 / 2, size = 2;
  ans[offset] = 0;
  ans[offset + 1] = p[0][0];
  as.insert(0);
  as.insert(p[0][0]);
  while (true) {
    set<int> bs, es;
    for (int i = 0; i < p[ans[offset]].size(); i++) {
      if (as.find(p[ans[offset]][i]) == as.end())
        bs.insert(p[ans[offset]][i]);
    }
    for (int i = 0; i < p[ans[offset + size - 1]].size(); i++) {
      if (as.find(p[ans[offset + size - 1]][i]) == as.end())
        es.insert(p[ans[offset + size - 1]][i]);
    }
    if (bs.size() + es.size() == 0) {
      cout << size << endl;
      cout << ans[offset] + 1;
      for (int i = 1; i < size; i++)
        cout << " " << ans[offset + i] + 1;
      cout << endl;
      break;
    } else {
      if (bs.size() > 0) {
        offset--;
        size++;
        ans[offset] = (*bs.begin());
        as.insert(*bs.begin());
      } else {
        size++;
        ans[offset + size - 1] = (*es.begin());
        as.insert(*es.begin());
      }
    }
  }

  return 0;
}
