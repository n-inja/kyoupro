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
vector<vector<int>> p;
vector<int> depth;
int n, q;
vector<int> member;

void dfs(int mem, int dep, int id) {
  if(member[id] != mem) return;
  if(depth[id] > 0) return;
  depth[id] = dep;
  for(int i = 0; i < p[id].size(); i++) {
    dfs(mem, dep + 1, p[id][i]);
  }
}

int search(int mem) {
  for(int i = 0; i < n; i++) depth[i] = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) if(member[i] == mem) cnt++;
  if(cnt == 1) {
    for(int i = 0; i < n; i++) {
      if(member[i] == mem) {
        cout << "! " << i + 1 << endl;
        exit(0);
      }
    }
  }
  for(int i = 0; i < n; i++) if(member[i] == mem) {
    dfs(mem, 1, i);
    break;
  }
  int par = 0;
  for(int i = 0; i < n; i++) if(depth[par] < depth[i]) par = i;
  for(int i = 0; i < n; i++) depth[i] = 0;
  dfs(mem, 1, par);
  vector<int> depmemo = depth;
  int par2 = 0;
  for(int i = 0; i < n; i++) if(depth[par2] < depth[i]) par2 = i;
  for(int i = 0; i < n; i++) depth[i] = 0;
  dfs(mem, 1, par2);
  for(int i = 0; i < n; i++) {
    if(member[i] < 0) continue;
    if(depmemo[i] == depth[i]) member[i] = 0;
    else if(depmemo[i] < depth[i]) member[i] = par + 1;
    else member[i] = par2 + 1;
  }
  cout << "? " << par + 1 << " " << par2 + 1 << endl;
  int ans;
  cin >> ans;
  for(int i = 0; i < n; i++) if(member[i] != ans) member[i] = -1;
  return ans;
}

int main() {
  cin >> n >> q;
  depth.resize(n);
  member.resize(n);
  p.resize(n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  int next = 0;
  for(int i = 0; i < q + 1; i++) {
    next = search(next);
  }
  return 0;
}
