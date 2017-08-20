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

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), ans;
  map<long long, int> mp;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) {
    mp[a[i]]++;
    if(mp[a[i]] == 2) {
      mp[a[i]] = 0;
      ans.push_back(a[i]);
    }
  }
  if(ans.size() < 2) {
    cout << 0 << endl;
  } else {
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 2] * ans[ans.size() - 1] << endl;
  }

  return 0;
}
