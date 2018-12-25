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
  string s;
  cin >> s;
  int a, b, c, d;
  a = s[0] - '0';
  b = s[1] - '0';
  c = s[2] - '0';
  d = s[3] - '0';
  for(unsigned int i = 0; i < 8; i++) {
    int ret = a;
    if((i & 1) > 0) ret += b;
    else ret -= b;
    if((i & 2) > 0) ret += c;
    else ret -= c;
    if((i & 4) > 0) ret += d;
    else ret -= d;
    if(ret == 7) {
      cout << a << (((i & 1) > 0) ? '+' : '-') << b << (((i & 2) > 0) ? '+' : '-') << c << (((i & 4) > 0) ? '+' : '-') << d << "=7" << endl;
      break;
    }
  }
  return 0;
}
