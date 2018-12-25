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
  long long n, h, a, b, c, d, e;
  cin >> n >> h >> a >> b >> c >> d >> e;
  h -= n*e;
  h = -h + 1;
  long long ans = 1145141919810364364;
  for(long long i = n; i >= 0; i--) {
    long long hs = h - i * (b + e);
    if(hs < 0) hs = 0;
    long long j = ((hs + d + e - 1) / (d + e));
    if(j < 0) j = 0;
    if(i + j <= n) {
      ans = min(ans, i*a + j*c);
    }
  }
  for(long long i = n; i >= 0; i--) {
    long long hs = h - i * (d + e);
    if(hs < 0) hs = 0;
    long long j = ((hs + b + e - 1) / (b + e));
    if(j < 0) j = 0;
    if(i + j <= n) {
      ans = min(ans, i*c + j*a);
    }
  }
  cout << ans << endl;
  return 0;
}
