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

class Increase {
public:
  int n, flowMax = 1000000;
  vector<vector<int>> p;
  vector<int> parent;
  Increase(int _n, vector<vector<int>> _p) {
    n = _n;
    p = _p;
    parent.resize(n);
  }
  int dfs(int id, int from, int flow) {
    if(parent[id] != id) return 0;
    parent[id] = from;
    if(id == n - 1) return flow;
    for(int i = 0; i < n; i++) if(p[id][i] > 0) {
      int next = dfs(i, id, min(flow, p[id][i]));
      if(next > 0) return next;
    }
    return 0;
  }
  int solve() {
    int ret = 0, flow;
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

int hx[4] = {0, 0, 1, -1};
int hy[4] = {1, -1, 0, 0};

int f(int a, int b) {
	if((a + b) % 2 == 0) return 1;
	else return -1;
}

int id(int y, int x, int r, int c) {
	return y * c + x + 1;
}

int main() {
	int r, c;
	cin >> r >> c;
	vector<string> mp(r);
	for(int i = 0; i < r; i++) cin >> mp[i];
	int size = r * c;
	vector<vector<int>> flow(size + 2);
	for(int i = 0; i < size + 2; i++) flow[i].resize(size + 2);
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mp[i][j] == '.' && f(i, j) > 0) flow[0][id(i, j, r, c)] = 1;
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mp[i][j] == '.' && f(i, j) < 0) flow[id(i, j, r, c)][size + 1] = 1;
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) for(int k = 0; k < 4; k++) {
		if(f(i, j) < 0 || mp[i][j] != '.') continue;
		int ny = i + hy[k], nx = j + hx[k];
		if(ny < 0 || ny >= r || nx < 0 || nx >= c || mp[ny][nx] != '.') continue;
		flow[id(i, j, r, c)][id(ny, nx, r, c)] = 1;
	}
	Increase solver(size + 2, flow);
	int cnt = 0;
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mp[i][j] == '.') cnt++;
	cout << cnt - solver.solve() << endl;
	return 0;
}

