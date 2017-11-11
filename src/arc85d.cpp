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

int n;
vector<long long> a;
long long z, w;
long long xdp[2001], ydp[2001];

int main() {
  cin >> n >> z >> w;
  a.resize(n + 1);
  a[0] = w;
  for(int i = 0; i < n; i++) cin >> a[i + 1];
  ydp[n] = xdp[n] = abs(a[n] - a[0]);
  for(int i = n - 1; i >= 0; i--) {
    xdp[i] = abs(a[n] - a[i]);
    for(int j = i + 1; j < n; j++) xdp[i] = max(xdp[i], ydp[j]);
    ydp[i] = abs(a[n] - a[i]);
    for(int j = i + 1; j < n; j++) ydp[i] = min(ydp[i], xdp[j]);
  }
  long long ans = xdp[n];
  for(int i = 0; i < 2000; i++) ans = max(ans, ydp[i]);
  cout << ans << endl;
  return 0;
}
