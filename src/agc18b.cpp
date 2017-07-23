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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a;
  vector<int> c;
  a.resize(n);
  c.resize(n);
  for(int i = 0; i < n; i++) {
    a[i].resize(m);
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int ans = n;
  set<int> excep;
  for(int i = 0; i < m; i++) {
    int sum = m;
    vector<int> ret;
    ret.resize(m);
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        if(excep.find(a[j][k]) == excep.end()) {
          ret[a[j][k]]++;
          break;
        }
      }
    }
    int id = 0;
    for(int j = 0; j < m; j++) {
      if(ret[id] < ret[j]) {
        id = j;
      }
    }
    ans = min(ans, ret[id]);
    excep.insert(id);
  }

  cout << ans << endl;
  return 0;
}
