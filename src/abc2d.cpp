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


int main() {
  vector<vector<bool>> v;
  int n, m;
  cin >> n >> m;
  v.resize(n);
  for(int i = 0; i < n; i++) v[i].resize(n);
  for(int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    v[t][f] = true;
    v[f][t] = true;
  }
  int ans = 1;
  for(int i = 1; i <= 4096; i++) {
    int j = i;
    vector<int> s;
    for(int k = 0; k < n; k++) {
      if(j & 1 == 1) s.push_back(k);
      j /= 2;
    }
    bool f = false;
    for(int k = 0; k < s.size(); k++) {
      for(int l = k + 1; l < s.size(); l++) {
        if(!v[s[k]][s[l]]) f = true;
      }
    }
    if(f) continue;
    ans = ans < s.size() ? s.size() : ans;
  }
  cout << ans << endl;
  return 0;
}
