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
  long long h;
  cin >> n >> h;
  vector<long long> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  auto it = upper_bound(b.begin(), b.end(), a[n - 1]);
  if(it == b.end()) {
    cout << (h + a[n - 1] - 1) / a[n - 1] << endl;
    return 0;
  }
  long long ans = 0;
  if(it == b.begin()) {
    for(int i = n - 1; i >= 0; i--) {
      ans++;
      h -= b[i];
      if(h <= 0) {
        cout << ans << endl;
        return 0;
      }
    }
  } else {
    it--;
    auto it2 = b.end();
    it2--;
    while(it2 != it) {
      ans++;
      h -= *it2;
      it2--;
      if(h <= 0) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << ans + (h + a[n - 1] - 1) / a[n - 1] << endl;
  return 0;
}
