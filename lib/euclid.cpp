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

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

// return (x, y) (a * x + b * y = gcd(a, b))
pair<long long, long long> exeuclid(long long a, long long b) {
  if (b == 0)
    return make_pair(1, 0);
  pair<long long, long long> ret = exeuclid(b, a % b);
  ret.first -= a / b * ret.second;
  return make_pair(ret.second, ret.first);
}

// v := [(modulo, reminder)]
// moduloes should be coprime
long long CRT(vector<pair<long long, long long>> v) {
  long long mod = 1;
  long long ret = 0;
  for (int i = 0; i < v.size(); i++) {
    pair<long long, long long> xy = exeuclid(mod, v[i].first);
    long long M = mod * v[i].first;
    long long l = ((v[i].second * mod) % M) * xy.first;
    l %= M;
    long long r = ((ret * v[i].first) % M) * xy.second;
    r %= M;
    ret = (l + r) % M;
    ret += M;
    ret %= M;
    mod = M;
  }
  return ret;
}
