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
  int now, d, id;
  vector<int> back;
} Node;

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.d < rhs.d;
}

bool operator>(const Node &lhs, const Node &rhs) {
  return lhs.d > rhs.d;
}

int main() {
  int n, g, e;
  cin >> n >> g >> e;
  vector<vector<pair<int, bool>>> p(n + 1);
  vector<vector<bool>> che(n + 1);
  vector<int> p0;
  for(int i = 0; i < g; i++) {
    int a;
    cin >> a;
    p[a].push_back(make_pair(n, false));
  }
  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    if(a == 0 || b == 0) {
      if(a < b) swap(a, b);
      p0.push_back(a);
      continue;
    }
    p[a].push_back(make_pair(b, false));
    p[b].push_back(make_pair(a, false));
    che[a].push_back(false);
    che[b].push_back(false);
  }
  int ans = 0;

  for(int i = 0; i < p0.size(); i++) {
    vector<int> v;
    multiset<Node> q;
    q.insert(Node{p0[i], 1, p0[i], v});
    vector<bool> che(n + 1);
    while(q.size() > 0) {
      Node now = *q.begin();
      q.erase(q.begin());
      if(che[now.now]) continue;
      che[now.now] = true;
      if(now.now == n) {
        ans++;
        int node = now.id;
        for(int j = 0; j < now.back.size(); j++) {
          p[node][now.back[j]].second = true;
          node = p[node][now.back[j]].first;
        }
        break;
      }
      for(int j = 0; j < p[now.now].size(); j++) {
        if(p[now.now][j].second || che[p[now.now][j].first]) continue;
        vector<int> v = now.back;
        v.push_back(j);
        q.insert(Node{p[now.now][j].first, now.d + 1, now.id, v});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
