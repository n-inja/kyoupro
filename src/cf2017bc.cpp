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

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> p(n);
  vector<set<int>> s(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    p[a].push_back(b);
    s[a].insert(b);
    p[b].push_back(a);
    s[b].insert(a);
  }
  return 0;
}
