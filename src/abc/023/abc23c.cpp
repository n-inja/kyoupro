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

const long long PRIME = 1000000007;

using namespace std;

int main() {
  int r, c, k, n;
  cin >> r >> c >> k >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  vector<int> w(c), h(r);
  map<int, int> val;
  map<int, set<int>> wm, hm;
  for(int i = 0; i < n; i++) {
    h[v[i].first - 1]++;
    w[v[i].second - 1]++;
    wm[v[i].second - 1].insert(v[i].first - 1);
    hm[v[i].first - 1].insert(v[i].second - 1);
  }
  for(int i = 0; i < c; i++) val[w[i]]++;
  long long ans = 0;
  for(int i = 0; i < r; i++) {
    if(h[i] > k) continue;
    if(h[i] == 0) ans += val[k];
    else {
      ans += val[k - h[i]];
      for(auto it = hm[i].begin(); it != hm[i].end(); it++) {
        if(h[i] + w[*it] == k) ans--;
        if(h[i] + w[*it] == k + 1) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
