#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct N {
  long long v, w;
  bool swapped;
};

bool operator<(const N &lhs, const N &rhs) { return lhs.v < rhs.v; }

int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long>> ps(n);
  for (int i = 0; i < n; i++)
    cin >> ps[i].first >> ps[i].second;
  long long mi = ps[0].first;
  long long ma = ps[0].first;
  for (int i = 0; i < n; i++) {
    mi = min(mi, ps[i].first);
    mi = min(mi, ps[i].second);
    ma = max(ma, ps[i].first);
    ma = max(ma, ps[i].second);
  }
  long long smi = ma;
  long long sma = mi;
  for (int i = 0; i < n; i++) {
    long long a = min(ps[i].first, ps[i].second);
    long long b = max(ps[i].first, ps[i].second);
    smi = min(smi, b);
    sma = max(sma, a);
  }
  long long ans = (ma - smi) * (sma - mi);
  multiset<N> q;
  sma = 0;
  for (int i = 0; i < n; i++) {
    q.insert(N{min(ps[i].first, ps[i].second), max(ps[i].first, ps[i].second),
               false});
    sma = max(sma, min(ps[i].first, ps[i].second));
  }
  for (int i = 0; i < 2 * n; i++) {
    N now = *q.begin();
    q.erase(q.begin());
    ans = min(ans, (ma - mi) * (sma - now.v));
    if (now.swapped) {
      break;
    }
    q.insert(N{now.w, now.v, true});
    sma = max(sma, now.w);
  }
  cout << ans << endl;
  return 0;
}
