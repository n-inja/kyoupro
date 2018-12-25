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
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans = -114514;
  for(int i = 0; i < n; i++) {
    int am = -114514, bm = -114514;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      int l = min(i, j), r = max(i, j);
      int odd = 0, eve = 0;
      for(int k = l; k <= r; k++) {
        if((k - l) % 2 == 0) eve += a[k];
        else odd += a[k];
      }
      if(bm < odd) {
        bm = odd;
        am = eve;
      }
    }
    ans = max(ans, am);
  }
  cout << ans << endl;
  return 0;
}
