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
  int n;
  cin >> n;
  vector<unsigned long long> v, cnt;
  v.resize(n);
  cnt.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  unsigned long long ans = 0, a = 0;
  while(true) {
    a = 0;
    for(int i = 0; i < n; i++) {
      ans += v[i] / n;
      a += v[i] / n;
      cnt[i] = v[i] / n;
    }
    for(int i = 0; i < n; i++) {
      v[i] = v[i] % n + a - cnt[i];
    }
    if(a == 0) {
      cout << ans << endl;
      break;
    }
  }
  return 0;
}
