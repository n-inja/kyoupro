#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

long long f(long long x, long long y, long long l, long long t, bool b) {
  long long d = y - x;
  if (!b)
    d = l - d;
  return (2 * t - d + l) / l;
}

int main() {
  long long n;
  long long l, t;
  cin >> n >> l >> t;
  vector<pair<long long, long long>> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  long long m = p[0].second;
  vector<long long> q;
  for (int i = 0; i < n; i++) {
    if (p[i].second != m)
      q.push_back(p[i].first);
  }
  long long ret = 0;
  for (int i = 0; i < q.size(); i++) {
    ret += f(p[0].first, q[i], l, t, m == 1);
  }
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    if (p[i].second == 1)
      v[i] = (p[i].first + t) % l;
    else
      v[i] = ((p[i].first - t) % l + l) % l;
  }
  sort(v.begin(), v.end());
  long long w;
  if (m == 1)
    w = (p[0].first + t) % l;
  else
    w = ((p[0].first - t) % l + l) % l;
  int id;
  for (int i = 0; i < n; i++) {
    if (w == v[i]) {
      id = i;
      if (m == 2)
        break;
    }
  }
  vector<long long> c(n);
  if (m == 2)
    ret *= -1;
  for (int i = 0; i < n; i++) {
    c[((ret + i) % n + n) % n] = v[(id + i) % n];
  }
  for (int i = 0; i < n; i++)
    cout << c[i] << endl;
  return 0;
}
