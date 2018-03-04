#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class RMQ {
  vector<unsigned int> data;

public:
  static const unsigned int BASE = 0;
  int n;
  RMQ(int _) {
    n = _;
    data.resize(n * 4);
    for (int i = 0; i < n * 4; i++)
      data[i] = BASE;
  }
  void update(int index, unsigned int val) {
    int i = index + n - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = max(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  // [a, b)
  unsigned int query(int a, int b, int k, int l, int r) {
    if (a < 0)
      return BASE;
    if (r <= a || b <= l)
      return BASE;
    if (a <= l && r <= b)
      return data[k];
    else
      return max(query(a, b, k * 2 + 1, l, (l + r) / 2),
                 query(a, b, k * 2 + 2, (r + l) / 2, r));
  }
  unsigned int query(int a, int b) { return query(a, b, 0, 0, n); }
};

struct Node {
  int start, end, id, size;
};

bool operator<(const Node &lhs, const Node &rhs) {
  if (lhs.start == rhs.start)
    return lhs.end < rhs.end;
  return lhs.start < rhs.start;
}

int main() {
  int n;
  cin >> n;
  vector<Node> nodes(n);
  vector<int> inv(n);
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].start >> nodes[i].end;
    nodes[i].id = i;
  }
  sort(nodes.begin(), nodes.end(),
       [](const Node &lhs, const Node &rhs) { return lhs.start > rhs.start; });
  for (int i = 0; i < n; i++)
    inv[nodes[i].id] = i;
  RMQ rmq(1 << 21);
  for (int i = 0; i < n; i++) {
    nodes[i].size = rmq.query(nodes[i].end, 1 << 21) + 1;
    rmq.update(nodes[i].start,
               max(rmq.query(nodes[i].start, nodes[i].start + 1),
                   (unsigned int)nodes[i].size));
  }
  vector<vector<Node>> q(n);
  vector<vector<int>> mins(n);
  for (int i = 0; i < n; i++) {
    q[nodes[i].size - 1].push_back(nodes[i]);
    mins[nodes[i].size - 1].push_back(n + 1);
  }
  for (int i = 0; i < n; i++)
    sort(q[i].begin(), q[i].end());
  for (int i = 0; i < n; i++) {
    for (int j = q[i].size() - 1; j >= 0; j--) {
      mins[i][j] = min(q[i][j].id, mins[i][j]);
      if (j < q[i].size() - 1)
        mins[i][j] = min(mins[i][j], mins[i][j + 1]);
    }
  }

  int st = 0;
  vector<int> ans;

  for (int i = n - 1; i >= 0; i--) {
    if (q[i].size() > 0) {
      auto it = lower_bound(q[i].begin(), q[i].end(), Node{st, st, -1});
      int id = mins[i][it - q[i].begin()];
      ans.push_back(id);
      st = nodes[inv[id]].end;
    }
  }
  cout << ans.size() << endl;
  cout << ans[0] + 1;
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i] + 1;
  cout << endl;
  return 0;
}
