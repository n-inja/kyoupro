#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

long long gcd(long long a, long long b) {
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main() {
  while(true) {
    string s;
    cin >> s;
    if(s == "#") break;
    reverse(s.begin(), s.end());

    long long a = 0, b = 1;
    if(s.substr(0, 5) == "htron") {
      s = s.substr(5, s.size());
    } else {
      a = 90;
      b = 1;
      s = s.substr(4, s.size());
    }
    while(s.size() > 0) {
      a *= 2; b *= 2;
      if(s.substr(0, 5) == "htron") {
        s = s.substr(5, s.size());
        a -= 90;
        if(a < 0) a = 0;
      } else {
        s = s.substr(4, s.size());
        a += 90;
        if(a > 90 * b) a = 90 * b;
      }
    }
    if(a == 0) {
      cout << 0 << endl;
      continue;
    }
    long long ansa = a / gcd(a, b), ansb = b / gcd(a, b);
    if(ansb == 1) {
      cout << ansa << endl;
      continue;
    }
    cout << ansa << "/" << ansb << endl;
  }
  return 0;
}
