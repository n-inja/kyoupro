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
#include<queue>

using namespace std;

long long powb(long long e, long long x, long long b) {
  if(x == 0) return 1;
  if(x == 1) return e % b;
  if(x % 2 == 0) return powb((e * e) % b, x / 2, b);
  return (e * powb(e, x - 1, b)) % b;
}

long long inva(long long a, long long b) {
  return powb(a, b - 2, b);
}

long long getAl(long long size, long long l, long long b) {
  if(l == 1) return 1;
  if(l % 2 == 0) {
    long long half = getAl(size, l / 2, b);
    return ((half * powb(powb(10, l / 2, b), size, b)) % b + half) % b;
  }
  return ((powb(10, size, b) * getAl(size, l - 1, b)) % b + 1) % b;
}

int numSize(long long a) {
  string s = to_string(a);
  return s.size();
}

int main() {
  int n;
  cin >> n;
  vector<pair<long long, int>> ps(n);
  for(int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;
  long long b;
  cin >> b;
  reverse(ps.begin(), ps.end());
  long long ans = 0;
  long long keta = 1;
  for(int i = 0; i < n; i++) {
    long long size = numSize(ps[i].first);
    ans = (ans + (ps[i].first * ((keta * getAl(size, ps[i].second, b)) % b) % b) % b) % b;
    for(int j = 0; j < size; j++) {
      keta = (keta * powb(10, ps[i].second, b)) % b;
    }
  }
  cout << ans << endl;
  return 0;
}
/*
an = (10^n-1)/9

an = ((10^3)^(n-1)*(10^3-2)+1)/(10^3-1)
al = ((10^size(a))^(l-1)*(10^size(a)-2)+1)/(10^size(a)-1)*10^keta
ans += a * al
keta += size(a) * l
*/
