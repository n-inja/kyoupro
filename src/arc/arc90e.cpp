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

struct Node {
  int id, from;
  long long cost;
};

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.cost < rhs.cost;
}

long long P = 1000000007;

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--; t--;
  vector<vector<pair<int, long long>>> p(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    long long d;
    cin >> u >> v >> d;
    u--; v--;
    p[u].push_back(make_pair(v, d * 2));
    p[v].push_back(make_pair(u, d * 2));
  }
  Node start{s, -1, 0};
  multiset<Node> q;
  q.insert(start);
  vector<long long> costs(n), costs2(n);
  vector<vector<int>> parent(n);
  vector<long long> num(n), num2(n);
  for(int i = 0; i < n; i++) costs[i] = costs2[i] = -1;
  for(int i = 0; i < n; i++) num[i] = num2[i] = -1;
  num[s] = 1;
  num2[t] = 1;
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(costs[t] >= 0 && costs[t] < now.cost) {
      q.clear();
      break;
    }
    if(costs[now.id] == now.cost) {
      num[now.id] = (num[now.id] + num[now.from]) % P;
      parent[now.id].push_back(now.from);
      continue;
    }
    if(costs[now.id] >= 0 && costs[now.id] < now.cost) continue;
    if(num[now.id] < 0) num[now.id] = num[now.from];
    costs[now.id] = now.cost;
    if(now.from >= 0) parent[now.id].push_back(now.from);
    for(int i = 0; i < p[now.id].size(); i++) {
      Node next{p[now.id][i].first, now.id, now.cost + p[now.id][i].second};
      if(costs[next.id] >= 0 && costs[next.id] < next.cost) continue;
      q.insert(next);
    }
  }
  Node start2{t, -1, 0};
  q.clear();
  q.insert(start2);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(costs2[s] >= 0 && costs2[s] < now.cost) {
      q.clear();
      break;
    }
    if(costs2[now.id] == now.cost) {
      num2[now.id] = (num2[now.id] + num2[now.from]) % P;
      continue;
    }
    if(costs2[now.id] >= 0 && costs2[now.id] < now.cost) continue;
    if(num2[now.id] < 0) num2[now.id] = num2[now.from];
    costs2[now.id] = now.cost;
    for(int i = 0; i < p[now.id].size(); i++) {
      Node next{p[now.id][i].first, now.id, now.cost + p[now.id][i].second};
      if(costs2[next.id] >= 0 && costs2[next.id] < next.cost) continue;
      q.insert(next);
    }
  }
  long long half = costs[t] / 2;
  vector<int> hv;
  vector<pair<int, int>> he;
  vector<bool> b(n);
  for(int i = 0; i < n; i++) b[i] = true;
  set<int> ss;
  ss.insert(t);
  while(ss.size() > 0) {
    int now = *ss.begin();
    ss.erase(ss.begin());
    b[now] = false;
    for(int i = 0; i < parent[now].size(); i++) {
      if(parent[now][i] < 0) continue;
      if(!b[parent[now][i]]) continue;
      ss.insert(parent[now][i]);
    }
  }
  q.clear();
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(b[now.id]) continue;
    b[now.id] = true;
    if(now.cost == half) {
      hv.push_back(now.id);
      continue;
    }
    if(half < now.cost) {
      q.clear();
      break;
    }
    for(int i = 0; i < p[now.id].size(); i++) {
      Node next{p[now.id][i].first, now.id, now.cost + p[now.id][i].second};
      if(b[next.id]) continue;
      if(next.cost > half && next.cost == costs[next.id]) {
        he.push_back(make_pair(now.id, next.id));
        continue;
      }
      q.insert(next);
    }
  }
  /*
  cout << "half time : " << half << endl;
  cout << "middle vertex" << endl;
  for(int i = 0; i < hv.size(); i++) cout << hv[i] << endl;
  cout << "middle edge" << endl;
  for(int i = 0; i < he.size(); i++) cout << he[i].first << " " << he[i].second << endl;
  */
  long long ans = (num[t] * num[t]) % P;
  for(int i = 0; i < n; i++) num[i] = (num[i] * num[i]) % P;
  for(int i = 0; i < n; i++) num2[i] = (num2[i] * num2[i]) % P;
  for(int i = 0; i < hv.size(); i++) {
    ans = (ans + (P - (num[hv[i]] * num2[hv[i]]) % P)) % P;
  }
  for(int i = 0; i < he.size(); i++) {
    ans = (ans + (P - (num[he[i].first] * num2[he[i].second]) % P)) % P;
  }
  cout << ans << endl;
  return 0;
}
