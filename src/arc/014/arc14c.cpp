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
 
int n;
set<string> words;
map<string, map<string, long double>> path;
map<string, pair<long double, long double>> c;
 
void dfs(string s, long double a, long double b) {
  if(c.find(s) != c.end()) return;
  c[s] = make_pair(a, b);
  for(auto it = path[s].begin(); it != path[s].end(); it++) {
    if(it->second > 0) dfs(it->first, a * it->second, b);
    else dfs(it->first, a, b * (-it->second));
  }
}
 
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    string l, s;
    long double m;
    cin >> l >> m >> s;
    path[l][s] = m;
    path[s][l] = -m;
    words.insert(l);
    words.insert(s);
  }
  long double ans = 0;
  string s, l;
  for(auto it = words.begin(); it != words.end(); it++) {
    c.clear();
    dfs(*it, 1, 1);
    long double ma = 0;
    string ms;
    for(auto it2 = c.begin(); it2 != c.end(); it2++) {
      if(ma < it2->second.first / it2->second.second) {
        ma = it2->second.first / it2->second.second;
        ms = it2->first;
      }
    }
    if(ans < ma) {
      ans = ma;
      s = ms;
      l = *it;
    }
  }
  cout << 1 << l << "=" << (long long)floor(ans + 0.1) << s << endl;
  return 0;
}