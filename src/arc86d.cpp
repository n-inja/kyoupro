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
  vector<int> a(n + 1);
  for(int i = 0; i < n; i++) cin >> a[i];
  a[n] = 0;
  int mbi = n, msi = n;
  for(int i = 0; i < n; i++) {
    if(a[mbi] < a[i]) mbi = i;
    if(a[msi] > a[i]) msi = i;
  }
  if(a[mbi] == 0 && a[msi] == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<pair<int, int>> ans;
  if(abs(a[mbi]) > abs(a[msi])) {
    ans.push_back(make_pair(mbi + 1, n));
    ans.push_back(make_pair(mbi + 1, n));
    for(int i = 0; i < n - 1; i++) {
      ans.push_back(make_pair(n, i + 1));
      ans.push_back(make_pair(n, n));
    }
  } else {
    ans.push_back(make_pair(msi + 1, 1));
    ans.push_back(make_pair(msi + 1, 1));
    for(int i = n - 1; i > 0; i--) {
      ans.push_back(make_pair(1, i + 1));
      ans.push_back(make_pair(1, 1));
    }
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
