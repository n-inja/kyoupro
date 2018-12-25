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
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for(int i = 0;i < n; i++) {
    int l, r, s;
    cin >> l >> r >> s;
    mp[0] += s;
    mp[l - 1] -= s;
    mp[r] += s;
    mp[m] -= s;
  }
  int ans = 0, sum = 0;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    sum += it->second;
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
