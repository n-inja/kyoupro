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

unsigned long long count(unsigned long long l) {
  vector<vector<unsigned long long>> c;
  string s = to_string(l);
  unsigned long long ans = 0;
  c.resize(s.size());
  c[0].push_back(0);
  c[0].push_back(0);
  c[0].push_back(0);
  c[0].push_back(1);
  c[0].push_back(0);
  c[0].push_back(0);
  c[0].push_back(0);
  c[0].push_back(0);
  c[0].push_back(1);
  c[0].push_back(2);
  for(int i = 1; i < s.size(); i++) {
    c[i].resize(10);
    for(int j = 1; j <= 9; j++) {
      string ss = to_string(j);
      if(ss == "4" || ss == "9") {
        c[i][j - 1] = pow(10, i);
      } else {
        c[i][j - 1] = c[i - 1][9];
      }
    }
    for(int j = 0; j < 9; j++) c[i][9] += c[i][j];
    c[i][9] += c[i - 1][9];
  }
  for(int i = s.size() - 1; i >= 0; i--) {
    if(s[s.size() - i - 1] == '0') continue;
    if(i > 0) ans += c[i - 1][9];
    for(int j = 0; j < s[s.size() - i - 1] - '1'; j++) ans += c[i][j];
    if(s[s.size() - i - 1] == '4' || s[s.size() - i - 1] == '9') {
      if(i == 0) {
        ans += 1;
      } else {
        ans += stoll(s.substr(s.size() - i, 20)) + 1;
      }
      break;
    }
  }
  return ans;
}

int main() {
  unsigned long long a, b;
  cin >> a >> b;
  cout << count(b) - count(a - 1) << endl;
  return 0;
}
