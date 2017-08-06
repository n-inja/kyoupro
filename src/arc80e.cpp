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

vector<vector<pair<int, int>>> ans;

void solve(auto be, auto en) {
  if(distance(be, en) == 1) return;
  vector<pair<int, int>> an;
  map<int, int> eu, ou;
  int i = 0;
  for(auto it = be; it != en; it++) {

    i++;
  }
}

int main() {
  int n;
  cin >> n;
  ans.resize(n/2);
  vector<int> p, ans;
  set<int> un, used;
  p.resize(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) p[i]--;
  for(int i = 0; i < n; i++) {
    un.insert(i);
  }
  map<int, int> mp;
  for(int i = 0; i < n; i++) mp[p[i]] = i;
  for(int i = 0; ans.size() < n; i++) {
    int s, a;
    for(auto it = un.begin(); it != un.end(); it++) {
      int ss = *it;
      auto lb = lower_bound(used.begin(), used.end(), mp[ss]);
      if((mp[ss] + distance(used.begin(), lb)) % 2 == 0) {
        s = ss;
        a = distance(used.begin(), lb);
        un.erase(it);
        break;
      }
    }
    int e;
    for(auto it = un.begin(); it != un.end(); it++) {
      int ee = *it;
      auto lb = lower_bound(used.begin(), used.end(), mp[ee]);
      if((mp[ee] + distance(used.begin(), lb)) % 2 == 1 && a == distance(used.begin(), lb)) {
        e = ee;
        un.erase(it);
        break;
      }
    }
    ans.push_back(s + 1);
    ans.push_back(e + 1);
    used.insert(mp[s]);
    used.insert(mp[e]);
  }
  cout << ans[0];
  for(int i = 1; i < n; i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
