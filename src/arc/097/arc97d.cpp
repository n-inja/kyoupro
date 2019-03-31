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
class UnionFind {
private:
  std::vector<int> data_array;
  const int root(int id) {
    if (data_array[id] >= 0)
      return data_array[id] = root(data_array[id]);
    else
      return id;
  }

public:
  UnionFind(size_t size) : data_array(size, -1) {}
  // unionは予約語
  bool union_(int lhs, int rhs) {
    lhs = root(lhs);
    rhs = root(rhs);
    bool is_union = (lhs != rhs);
    if (is_union) {
      if (data_array[lhs] > data_array[rhs]) {
        std::swap(lhs, rhs);
      }
      data_array[lhs] += data_array[rhs];
      data_array[rhs] = lhs;
    }
    return is_union;
  }
  bool find(int lhs, int rhs) { return (root(lhs) == root(rhs)); }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  vector<pair<int, int>> xy(m);
  for (int i = 0; i < m; i++)
    cin >> xy[i].first >> xy[i].second;
  UnionFind u(n);
  for (int i = 0; i < m; i++)
    u.union_(xy[i].first - 1, xy[i].second - 1);
  vector<int> invp(n);
  for (int i = 0; i < n; i++)
    invp[p[i] - 1] = i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (u.find(p[i] - 1, invp[p[i] - 1]))
      ans++;
  }
  cout << ans << endl;
  return 0;
}
