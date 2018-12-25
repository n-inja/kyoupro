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

#define P 1000000007

using namespace std;


int n;
vector<vector<int>> v;
vector<vector<long long>> c;
vector<long long> w;

void dfs(int now, long long d) {
  if(w[now] >= 0) return;
  w[now] = d;
  for(int i = 0; i < v[now].size(); i++) {
    if(w[v[now][i]] >= 0) continue;
    dfs(v[now][i], d + c[now][i]);
  }
}

int main() {
  cin >> n;
  v.resize(n);
  c.resize(n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    long long d;
    cin >> a >> b >> d;
    a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
    c[a].push_back(d);
    c[b].push_back(d);
  }
  w.resize(n);
  for(int i = 0; i < n; i++) w[i] = -1;
  int q, k;
  cin >> q >> k;
  dfs(k - 1, 0);
  for(int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << w[x] + w[y] << endl;
  }

  return 0;
}
