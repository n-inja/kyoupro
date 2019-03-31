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

class U {
public:
  int n;
  vector<int> p, s;
  U(int _) {
    n = _;
    p.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 0;
    }
  }
  int check(int id) {
    if(id < 0 || id >= n) return 0;
    if(p[id] == id && s[id] == 0) return 0;
    int pid = id;
    for(; pid != p[pid]; pid = p[pid]);
    return s[pid];
  }
  void connect(int a, int b) {
    if(b < a) swap(a, b);
    int pa = a, pb = b;
    for(; pa != p[pa]; pa = p[pa]);
    for(; pb != p[pb]; pb = p[pb]);
    int parent = min(pa, pb);
    if(pa == pb) return;
    pa = a; pb = b;
    int sum = 0;
    while(true) {
      int next = p[pa];
      p[pa] = parent;
      sum += s[pa];
      s[pa] = 0;
      if(pa == next || next == parent) break;
      pa = next;
    }
    while(true) {
      int next = p[pb];
      p[pb] = parent;
      sum += s[pb];
      s[pb] = 0;
      if(pb == next || next == parent) break;
      pb = next;
    }
    s[parent] += sum;
  }
  void add(int id) {
    s[id] = 1;
    if(id > 0 && check(id - 1) > 0) {
      connect(id - 1, id);
    }
    if(id < n - 1 && check(id + 1) > 0) {
      connect(id, id + 1);
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  vector<int> ans(n);
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++) {
    p[i].first = i;
    p[i].second = h[i];
  }
  sort(p.begin(), p.end(), [](const pair<int, int> lhs, const pair<int, int> rhs) {
    return lhs.second < rhs.second;
  });
  U u(n);
  vector<int> stock;
  for(int i = 0; i < n; i++) {
    u.add(p[i].first);
    stock.push_back(p[i].first);
    if(i < n - 1) {
      if(p[i + 1].second == p[i].second) {
        continue;
      }
    }
    for(int j = 0; j < stock.size(); j++) {
      ans[stock[j]] += u.check(stock[j]) - 1;
    }
    stock.clear();
  }
  for(int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
}
