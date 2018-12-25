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
 
using namespace std;
 
long long gcd(long long a, long long b) {
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}

bool search(long long n, long long x, long long y) {
  if(n % y != 0) return false;
  long long xy = n / y;
  x *= xy; y *= xy;
  // (n * (n + 1) / 2 - m) = x
  long long m = n * (n + 1) / 2 - x;
  if(m > 0 && m <= n) {
    cout << n << " " << m << endl;
    return true;
  }
  return false;
}
 
int main() {
  long long x, y;
  char c;
  cin >> x >> c >> y;
  long long xy = gcd(x, y);
  x /= xy; y /= xy;
  long long n = x / y * 2;
  bool b = false;
  for(long long i = -3; i < 4; i++) {
    if(n + i > 0) b |= search(n + i, x, y);
  }
  if(!b) cout << "Impossible" << endl;
  return 0;
}