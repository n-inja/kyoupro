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
  int n;
  cin >> n;
  vector<long long> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  int m;
  cin >> m;
  vector<long long> t(m);
  for(int i = 0; i < m; i++) cin >> t[i];
  sort(d.begin(), d.end());
  sort(t.begin(), t.end());

  int di = 0;
  for(int i = 0; i < m; i++) {
    if(di >= n) {
      cout << "NO" << endl;
      return 0;
    }
    if(d[di] == t[i]) {
      di++;
      continue;
    } else if(d[di] < t[i]) {
      di++;
      i--;
      continue;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
