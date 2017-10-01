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

long long n, t;
vector<long long> a, b;

bool f(long long s){
  vector<long long> c(n);
  for(int i = 0; i < n; i++) c[i] = b[i] - a[i];
  sort(c.begin(), c.end());
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
  }
  for(int i = 0; i < s; i++) {
    sum += c[i];
  }
  if(sum <= t) return true;
  else return false;
}

int main() {
  cin >> n >> t;
  a.resize(n);
  b.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long amin = 0, amax = n;
  if(!f(n)) {
    cout << -1 << endl;
    return 0;
  }
  if(f(0)) {
    cout << 0 << endl;
    return 0;
  }
  while(amax - amin > 1) {
    long long piv = (amax + amin) / 2;
    if(f(piv)) amax = piv;
    else amin = piv;
  }
  cout << amax << endl;
	return 0;
}
