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

typedef struct {
  int now;
  long long cost;
} Node;

bool operator>(const Node &lhs, const Node &rhs) {
  return lhs.cost > rhs.cost;
}

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.cost < rhs.cost;
}

int main() {
  int n, m;
  long long t;
  cin >> n >> m >> t;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<vector<pair<int, long long>>> p(n), p2(n);
  for(int i = 0; i < m; i++) {
    int a1, b1;
    long long c1;
    cin >> a1 >> b1 >> c1;
    a1--; b1--;
    p[a1].push_back(make_pair(b1, c1));
    p2[b1].push_back(make_pair(a1, c1));
  }
  multiset<Node> q;
  q.insert(Node{0, 0});
  vector<bool> b(n);
  vector<pair<long long, long long>> c(n);
  for(int i = 0; i < n; i++) c[i] = make_pair(t, t);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(b[now.now]) continue;
    b[now.now] = true;
    c[now.now].first = now.cost;
    for(int i = 0; i < p[now.now].size(); i++) {
      Node next{p[now.now][i].first, now.cost + p[now.now][i].second};
      if(b[next.now]) continue;
      q.insert(next);
    }
  }
  for(int i = 0; i < n; i++) b[i] = false;
  q.insert(Node{0, 0});
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(b[now.now]) continue;
    b[now.now] = true;
    c[now.now].second = now.cost;
    for(int i = 0; i < p2[now.now].size(); i++) {
      Node next{p2[now.now][i].first, now.cost + p2[now.now][i].second};
      if(b[next.now]) continue;
      q.insert(next);
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, (t - c[i].first - c[i].second) * a[i]);
  cout << ans << endl;

  return 0;
}
