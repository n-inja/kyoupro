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

#define P 1000000007

using namespace std;

vector<vector<int>> v;
vector<int> c;

void dfs(int i, int n) {
  if(c[i] || n == 0) return;
  c[i] = true;
  for(int j = 0; j < v[i].size(); j++) {
    if(c[v[i][j]]) continue;
    dfs(v[i][j], n - 1);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  v.resize(n);
  c.resize(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0, 3);
  if(c[n - 1]) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
