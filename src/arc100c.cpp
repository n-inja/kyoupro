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
vector<long long> a;
long long f(long long b) {
  long long ret = 0;
  for (int i = 0; i < a.size(); i++)
    ret += abs(a[i] - b - i - 1);
  return ret;
}
int main() {
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<long long, int> mp;
  for (int i = 0; i < n; i++)
    mp[a[i] - i - 1]++;
  long long ans = f(mp.begin()->first);
  long long cnt = mp.begin()->second;
  long long sum = ans;
  long long bef = mp.begin()->first;
  auto it = mp.begin();
  for (it++; it != mp.end(); it++) {
    sum += (-n + 2 * cnt) * (it->first - bef);
    ans = min(ans, sum);
    bef = it->first;
    cnt += it->second;
  }
  cout << ans << endl;
  return 0;
}
