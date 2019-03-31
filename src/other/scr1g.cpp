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

long long power(long long e, long long x) {
  if(x == 0) return 1;
  if(x == 1) return e;
  if(x % 2 == 0) return power((e * e) % PRIME, x / 2);
  return (e * power(e, x - 1)) % PRIME;
}

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  string s = "";

  for(int i = 0; i < n; i++) {
    string b;
    cin >> b;
    s += b;
  }

  for(int i = s.size() - 1; i >= 0; i--) {
    ans = (ans + ((s[s.size() - i - 1] - '0') * power(10, i)) % PRIME) % PRIME;
  }
  cout << ans << endl;
  return 0;
}
