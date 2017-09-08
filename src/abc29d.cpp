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

long long power(long long e, long long x) {
  if(x == 0) return 1;
  if(x == 1) return e;
  if(x < 0) return 0;
  if(x % 2 == 0) return power(e * e, x / 2);
  return e * power(e, x - 1);
}

long long f(string s, int x) {
  long long ans = 0, up = 0, down = 0;
  if(x > 0) up = stoll(s.substr(0, x));
  if(x < s.size() - 1) down = stoll(s.substr(x + 1, s.size()));
  ans += up * power(10, s.size() - x - 1);
  if(s[x] == '0') return ans;
  if(s[x] == '1') return ans + down + 1;
  return ans + power(10, s.size() - x - 1);
}

int main() {
  string s;
  cin >> s;
  long long ans = 0;
  for(int i = 0; i < s.size(); i++) ans += f(s, i);
  cout << ans << endl;
  return 0;
}
