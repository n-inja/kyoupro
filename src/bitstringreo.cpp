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
  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> b[i];
  vector<int> p(m);
  for(int i = 0; i < m; i++) cin >> p[i];
  int ac = 0, bc = 0;
  for(int i = 0; i < m; i++) {
    if(i % 2 == 0) ac += p[i];
    else bc += p[i];
  }
  int b0 = 0, b1 = 0;
  for(int i = 0; i < n; i++) if(b[i] == 1) b1++;
  else b0++;
  int ans0 = 1000000, ans1 = 10000000;
  vector<int> b0p;
  for(int i = 0; i < n; i++) if(b[i] == 0) b0p.push_back(i);
  if(b0 == ac) {
    ans0 = 0;
    int c = 0, pos = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < p[i]; j++) {
        if(i % 2 == 1) pos++;
        else {
          ans0 += abs(pos - b0p[c]);
          c++;
          pos++;
        }
      }
    }
  }
  if(b0 == bc) {
    ans1 = 0;
    int c = 0, pos = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < p[i]; j++) {
        if(i % 2 == 0) pos++;
        else {
          ans1 += abs(pos - b0p[c]);
          c++;
          pos++;
        }
      }
    }
  }
  cout << min(ans0, ans1) << endl;
  return 0;
}
