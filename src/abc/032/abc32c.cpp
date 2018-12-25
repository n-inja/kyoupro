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
  long long k;
  cin >> n >> k;
  vector<long long> s(n);
  vector<bool> b(n);
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) if(s[i] > k) b[i] = true;
  for(int i = 0; i < n; i++) if(s[i] == 0) {
    cout << n << endl;
    return 0;
  }
  long long pro = 1;
  int l = 0, r = 0;
  int ans = 0;
  for(; r < n; r++) {
    if(b[r]) {
      l = r + 1;
      pro = 1;
      continue;
    }
    pro *= s[r];
    if(pro > k) while(pro > k) pro /= s[l++];
    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
  return 0;
}
