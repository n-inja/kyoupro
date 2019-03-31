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



class Increase {
public:
  long long n, flowMax = 10000000000;
  vector<vector<long long>> p;
  vector<int> parent;
  Increase(int _n, vector<vector<long long>> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
  }
  long long dfs(int id, int from, long long flow) {
    if(parent[id] != id) return 0;
    parent[id] = from;
    if(id == n - 1) return flow;
    for(int i = 0; i < n; i++) if(p[id][i] > 0) {
      int next = dfs(i, id, min(flow, p[id][i]));
      if(next > 0) return next;
    }
    return 0;
  }
  long long solve() {
    long long ret = 0, flow;
    for(int i = 0; i < n; i++) parent[i] = i;

    while((flow = dfs(0, -1, flowMax)) > 0) {
      int now = n - 1;
      ret += flow;
      while(parent[now] >= 0) {
        p[parent[now]][now] -= flow;
        p[now][parent[now]] += flow;
        now = parent[now];
      }
      for(int i = 0; i < n; i++) parent[i] = i;
    }
    return ret;
  }
};


int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  long long sum = 0;
  for(int i = 0; i < n; i++) if(a[i] > 0) sum += a[i];
  vector<vector<long long>> p(n + 2);
  for(int i = 0; i < n + 2; i++) p[i].resize(n + 2);
  for(int i = 0; i < n; i++) {
    if(a[i] <= 0) p[0][i + 1] = -a[i];
    else p[i + 1][n + 1] = a[i];
  }
  for(int i = 1; i < n + 1; i++) {
    for(int j = 2 * i; j < n + 1; j += i) p[i][j] = 10000000000;
  }

  Increase inc(n + 2, p);
  cout << sum - inc.solve() << endl;

  return 0;
}
