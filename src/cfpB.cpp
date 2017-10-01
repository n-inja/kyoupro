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

long long power(long long e, long long x) {
  if(x == 0) return 1;
  if(x % 2 == 0)return power(e * e, x / 2);
  return e * power(e, x - 1);
}

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    ans += a * power(2, n - i - 1);
  }
  cout << ans << endl;
	return 0;
}
