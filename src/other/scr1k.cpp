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

const long long PRIME = 1000000007;

using namespace std;

class BIT {
public:
  int n;
  vector<int> bit;
  BIT(int n_) {
    n = n_;
    bit.resize(n + 1);
  }
  void add(int a, int w) {
    if(a == 0 || a > n) return;
    for(int x = a; x <= n; x += x & -x) bit[x] += w;
  }
  int sum(int a) {
    if(a == 0) return 0;
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<long long> fac(n + 1);
  fac[0] = 1;
  for(int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % PRIME;

  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) v[i]--;

  long long ans = 1;
  BIT bit(n);
  for(int i = 0; i < n; i++) {
    ans += ((v[i] - bit.sum(v[i] + 1)) * fac[n - i - 1]) % PRIME;
    ans %= PRIME;
    bit.add(v[i] + 1, 1);
  }
  cout << ans << endl;
  return 0;
}
