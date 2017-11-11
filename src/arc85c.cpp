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

#define P 1000000007

using namespace std;

long long power(long long n, long long x) {
  if(x == 0) return 1;
  if(x == 1) return n;
  if(x % 2 == 0) return power(n * n, x / 2);
  return n * power(n, x - 1);
}

int main() {

  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  ans = (100 * (n - m) + 1900 * m) * power(2, m);
  cout << ans << endl;

  return 0;
}
