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

long long P = 1000000007;

map<long long, int> p;

void div(long long a) {
  if (a == 0)
    return;
  while (a % 2 == 0) {
    p[2]++;
    a /= 2;
  }
  for (long long i = 3; i * i <= a; i += 2) {
    if (a % i == 0) {
      p[i]++;
      div(a / i);
      return;
    }
  }
  if (a > 1)
    p[a]++;
  return;
}

int main() {
  long long a, b;
  cin >> a >> b;
  for (long long i = b + 1; i <= a; i++) {
    div(i);
  }
  long long ans = 1;
  for (auto it : p) {
    ans = (ans * (it.second + 1)) % P;
  }
  cout << ans << endl;
  return 0;
}
