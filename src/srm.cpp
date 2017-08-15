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

class Family {
public:
  vector<int> s;
  vector<vector<int>> p;
  Family(){}
  bool dfs(int i, int sa) {
    if(s[i] == -1) {
      s[i] = (sa+1)%2;
      bool ans = true;
      for(int j = 0; j < p[i].size(); j++) {
        if(!dfs(p[i][j], (sa + 1)%2)) {
          ans = false;
        }
      }
      return ans;
    } else if(s[i] == sa) {
      return false;
    }
    return true;
  }
  string isFamily(vector<int> p1, vector<int> p2) {
    int n = p1.size();
    s.resize(n);
    p.resize(n);
    for(int i = 0; i < n; i++) {
      if(p1[i] >= 0) {
        p[p1[i]].push_back(p2[i]);
        p[p2[i]].push_back(p1[i]);
      }
    }
    for(int i = 0; i < n; i++) {
      if(p[i].size() > 0 && s[i] == -1) {
        if(!dfs(i, 0)) {
          return "Impossible";
        }
      }
    }
    return "Possible";
  }
};


int main() {
  return 0;
}
