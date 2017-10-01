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

long long n, m;
vector<long long> x;

long long _max(long long a, long long b) {
  return a > b ? a : b;
}

long long _min(long long a, long long b) {
  return a < b ? a : b;
}

bool f(long long t) {
  long long a = 0;
  for(int i = 0; i < m; i++) {
    if(x[i] - a > t) return false;
    long long l = x[i] - a, r = x[i + 1] - x[i] - 1;
    a = _max(x[i] + 1 + (t - l * 2), x[i] + 1 + (t - l) / 2);
    if(a > x[i + 1]) a = x[i + 1];
  }
  if(a == n) return true;
  else return false;
}

int main() {
  cin >> n >> m;
  x.resize(m + 1);
  for(int i = 0; i < m; i++) cin >> x[i];
  for(int i = 0; i < m; i++) --x[i];
  x[m] = n;
  long long tmin = 0, tmax = n * 3;
  if(f(tmin)) {
    cout << 0 << endl;
    return 0;
  }
  while(tmax - tmin > 1) {
    long long piv = (tmax + tmin) / 2;
    if(f(piv)) tmax = piv;
    else tmin = piv;
  }
  cout << tmax << endl;
	return 0;
}
