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

struct Node {
  long long num;
  char c;
};

int main() {
  long long n, l;
  cin >> n >> l;
  vector<pair<long long, char>> xd(n);
  for (long long i = 0; i < n; i++)
    cin >> xd[i].first >> xd[i].second;
  sort(xd.begin(), xd.end(),
       [](const pair<long long, char> &lhs, const pair<long long, char> &rhs) {
         return lhs.first < rhs.first;
       });
  long long ans = 0;
  map<long long, Node> nodes;
  for (long long i = 0; i < n; i++) {
    if (xd[i].second == 'R') {
      long long id = i;
      while (++id < n && xd[id].second == 'R')
        ;
      for (long long j = i; j < id - 1; j++)
        ans += xd[id - 1].first - xd[j].first - (id - 1 - j);
      nodes[xd[id - 1].first] = Node{id - i, 'R'};
      i = id - 1;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (xd[i].second == 'L') {
      long long id = i;
      while (--id >= 0 && xd[id].second == 'L')
        ;
      for (long long j = i; j > id + 1; j--)
        ans += xd[j].first - xd[id + 1].first - (j - id - 1);
      nodes[xd[id + 1].first] = Node{i - id, 'L'};
      i = id + 1;
    }
  }
  if (nodes.begin()->second.c == 'L')
    nodes[0] = Node{0, 'R'};
  auto endit = nodes.end();
  endit--;
  if (endit->second.c == 'R')
    nodes[l + 1] = Node{0, 'L'};
  for (auto it = nodes.begin(); it != nodes.end(); it++) {
    long long pos = it->first;
    Node node = it->second;
    it++;
    long long dist = it->first - pos - 1;
    ans += dist * max(node.num, it->second.num);
  }
  cout << ans << endl;
  return 0;
}
