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
int main() {
  unsigned long long n, k;
  cin >> n >> k;
  vector<pair<unsigned long long, unsigned long long>> p(n);
  for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  unsigned long long ans = 0, ans2 = 0;
  for(int i = 0; i < n; i++) if((~k & p[i].first) == 0) ans += p[i].second;
  int id = 0;
  unsigned long long kk = k;
  for(int i = 0; kk > 0; i++) {
    id = i;
    kk /= 2;
  }
  for(int i = 1; i <= id; i++) {
    if((k & (1 << i)) == 0) continue;
    unsigned long long kf = (k ^ (1 << i)) | ((1 << i) - 1);
    ans2 = 0;
    for(int j = 0; j < n; j++) if((~kf & p[j].first) == 0) ans2 += p[j].second;
    ans = max(ans, ans2);
  }
  cout << ans << endl;
  return 0;
}
