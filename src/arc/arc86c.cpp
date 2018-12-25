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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> ia(n);
  for(int i = 0; i < n; i++) ia[a[i] - 1]++;
  map<int, int> mp;
  int rest = 0;
  for(int i = 0; i < n; i++) {
    if(ia[i] > 0) {
      mp[ia[i]]++;
      rest++;
    }
  }
  int ans = 0;
  if(rest <= k) {
    cout << 0 << endl;
    return 0;
  }
  for(auto it = mp.begin(); it != mp.end(); it++) {
    if(rest - it->second < k) {
      ans += it->first * (rest - k);
      break;
    }
    rest -= it->second;
    ans += it->first * it->second;
  }
  cout << ans << endl;
  return 0;
}
