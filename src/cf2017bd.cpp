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
  string s;
  cin >> n >> s;
  int ans = 0;
  vector<int> sc;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') {
      cnt++;
      continue;
    }
    if(s[i] == '0') {
      sc.push_back(cnt);
      cnt = 0;
    }
  }
  sc.push_back(cnt);
  sc.push_back(0);
  int id = 0;
  for(int i = 0; i < sc.size(); i++) {
    if(sc[i] == 0) {
      if(i - id < 2) {
        id = i + 1;
        continue;
      }
      int sum = 0;
      int l = id, r = i - 1;
    //  cout << l << " " << r << endl;
      while(r - l > 1) {
        if(sc[l + 1] > 1) {
          sum += sc[l];
          sc[l] = 0;
          sc[l + 1] -= 1;
          l++;
          continue;
        }
        if(sc[r - 1] > 1) {
          sum += sc[r];
          sc[r] = 0;
          sc[r - 1] -= 1;
          r--;
          continue;
        }
        if(sc[r] > sc[l]) {
          sum += sc[r];
          sc[r] = 0;
          sc[r - 1] -= 1;
          r--; r--;
        } else {
          sum += sc[l];
          sc[l] = 0;
          sc[l + 1] -= 1;
          l++; l++;
        }
      }
      if(r - l == 1) {
        sum += max(sc[r], sc[l]);
      }
      ans += sum;
      id = i + 1;
    }
  }
  for(int i = 0; i < sc.size(); i++) cout << sc[i] << endl;
  cout << ans << endl;
  return 0;
}
