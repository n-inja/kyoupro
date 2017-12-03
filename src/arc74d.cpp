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

int main() {
  int n;
  cin >> n;
  vector<long long> a(3 * n);
  for(int i = 0; i < n * 3; i++) cin >> a[i];
  long long fsum = 0, bsum = 0;
  map<long long, int> fmp, bmp;
  for(int i = 0; i < n; i++) fmp[a[i]]++;
  for(int i = 0; i < n; i++) fsum += a[i];
  for(int i = 2 * n; i < 3 * n; i++) bmp[-a[i]]++;
  for(int i = 2 * n; i < 3 * n; i++) bsum += a[i];
  vector<long long> fsubsum(n + 1), bsubsum(n + 1);
  fsubsum[0] = fsum;
  for(int i = 0; i < n; i++) {
    fsubsum[i + 1] = fsubsum[i];
    if(a[i + n] > fmp.begin()->first) {
      fmp.begin()->second--;
      fsubsum[i + 1] -= fmp.begin()->first;
      if(fmp.begin()->second == 0) fmp.erase(fmp.begin());
      fmp[a[i + n]]++;
      fsubsum[i + 1] += a[i + n];
    }
  }
  bsubsum[0] = bsum;
  for(int i = 0; i < n; i++) {
    bsubsum[i + 1] = bsubsum[i];
    if(-a[- i - 1 + 2 * n] > bmp.begin()->first) {
      bmp.begin()->second--;
      bsubsum[i + 1] += bmp.begin()->first;
      if(bmp.begin()->second == 0) bmp.erase(bmp.begin());
      bmp[-a[- i - 1 + 2 * n]]++;
      bsubsum[i + 1] += a[- i - 1 + 2 * n];
    }
  }
  long long ans = fsubsum[0] - bsubsum[n];
  for(int i = 1; i < n + 1; i++) ans = max(ans, fsubsum[i] - bsubsum[n - i]);

  cout << ans << endl;
  return 0;
}
