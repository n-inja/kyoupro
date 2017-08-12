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

long long gdc(long long a, long long b) {
  if(a > b) swap(a, b);
  if(a == 1) return 1;
  if(b % a == 0) return a;
  return gdc(a, b%a);
}

int main() {
  int n;
  cin >> n;
  vector<long long> t(n);
  for(int i = 0; i < n; i++) cin >> t[i];
  long long ans = 1;
  for(int i = 0; i < n; i++) {
    ans *= (t[i] / gdc(ans, t[i]));
  }
  cout << ans << endl;
  return 0;
}
