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

long long gcd(long long a, long long b) {
  long long c;
  while (a != 0) {
    c = a; a = b%a;  b = c;
  }
  return b;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long > a;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  bool b = true;
  for(int i = 0; i < n; i++) {
    if(a[i] == k) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
    if(a[i] > k) {
      b = false;
    }
  }
  if(b) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(n == 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  long long gc = gcd(a[1], a[0]);
  for(int i = 0; i < n - 1; i++) {
    long long a1 = min(gc, a[i + 1]);
    long long a2 = max(gc, a[i + 1]);
    gc = gcd(a2, a1);
  }
  if(k % gc == 0) {
    cout << "POSSIBLE" << endl;
    return 0;
  } else {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  return 0;
}
