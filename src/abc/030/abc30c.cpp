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
  long long x, y;
  cin >> x >> y;
  vector<long long> a(n), b(m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  int ans = 0;
  bool is = true;
  long long t = 0;
  for(int i = 0; i < n + m; i++) {
    if(is) {
      auto it = lower_bound(a.begin(), a.end(), t);
      if(it == a.end()) break;
      is = false;
      t = *it + x;
    } else {
      auto it = lower_bound(b.begin(), b.end(), t);
      if(it == b.end()) break;
      ans++;
      t = *it + y;
      is = true;
    }
  }
  cout << ans << endl;
  return 0;
}
