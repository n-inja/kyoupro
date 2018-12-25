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
int n;
long long x;
vector<long long> v, w;

long long llm = (1ll << 62);

long long f(int m) {
  long long ret = x * (n + m);
  long long k = 1;
  ret += 2 * (w[n] - w[n - m]);
  for (int i = n - 1; i >= 0;) {
    if (ret + (2 * k + 1) * (w[i + 1] - w[max(0, i + 1 - m)]) < ret)
      return llm;
    ret += (2 * k + 1) * (w[i + 1] - w[max(0, i + 1 - m)]);
    k++;
    i -= m;
  }
  return ret;
}

int main() {
  cin >> n >> x;
  v.resize(n);
  w.resize(n + 1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    w[i + 1] = w[i] + v[i];
  long long m = f(1);
  for (int i = 2; i <= n; i++)
    m = min(m, f(i));
  cout << m << endl;
  return 0;
}
