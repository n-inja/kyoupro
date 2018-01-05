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
  vector<long long> v(n);
  map<long long, long long> mp;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) mp[v[i]]++;
  long long ans = 0;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    if(it->second >= it->first) ans += it->second - it->first;
    else ans += it->second;
  }
  cout << ans << endl;
  return 0;
}
