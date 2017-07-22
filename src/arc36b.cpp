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
  vector<long long> h;
  h.resize(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  vector<int> ans;
  int ret = 0;
  bool up = true;
  for(int i = 0; i < n - 1; i++) {
    if(up) {
      if(h[i + 1] - h[i] > 0) {
        ret++;
      } else {
        ans.push_back(ret);
        ret = 1;
        up = false;
      }
    } else {
      if(h[i + 1] - h[i] < 0) {
        ret++;
      } else {
        ans.push_back(ret);
        ret = 1;
        up = true;
      }
    }
  }
  ans.push_back(ret);
  if(up) {
    ans.push_back(0);
  }
  int ansMax = 0;
  for(int i = 0; i < ans.size(); i += 2) {
    ansMax = max(ansMax, ans[i] + ans[i + 1]);
  }
  cout << ansMax + 1 << endl;
  return 0;
}
