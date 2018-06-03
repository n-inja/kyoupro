#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

long long cn2(long long n) { return n * (n - 1) / 2; }

int main() {
  long long n, d;
  cin >> n >> d;
  vector<long long> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  long long ans = n * (n - 1) * (n - 2) / 2 / 3;
  long long s[100001] = {0};
  long long ss[100002] = {0};
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(x.begin(), x.end(), x[i] + d);
    s[i] = x.end() - it;
  }
  ss[0] = 0;
  for (int i = 1; i <= n; i++) {
    ss[i] = ss[i - 1] + s[i - 1];
  }
  for (int i = 0; i < n; i++) {
    auto lit = upper_bound(x.begin(), x.end(), x[i]);
    auto rit = upper_bound(x.begin(), x.end(), x[i] + d);
    rit--;
    if (*lit > x[i] + d) {
      ans -= cn2(n - i - 1);
      continue;
    }
    ans -= cn2(rit - lit + 1);
    int rid = min(n - 1, (long long)(rit - x.begin()));
    int lid = min(n - 1, (long long)(lit - x.begin()));
    rid++;
    ans -= ss[rid] - ss[lid];
    ans -= cn2(s[i]);
    //    cerr << lid << " " << rid << endl;
    //    cerr << i << " " << cn2(rit - lit + 1) << " " << ss[rid] - ss[lid] <<
    //    " "
    //         << cn2(s[i]) << endl;
  }
  cout << ans << endl;
  return 0;
}
