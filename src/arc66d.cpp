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
long long n;
map<long long, long long> memo;

long long f(long long x) {
  if (memo.find(x) != memo.end())
    return memo[x];
  long long ret = 0;
  ret = (ret + f(x / 2)) % P;
  ret = (ret + f((x - 1) / 2)) % P;
  ret = (ret + f(x / 2 - 1)) % P;
  return memo[x] = ret;
}

int main() {
  memo[0] = 1;
  memo[1] = 2;
  cin >> n;
  cout << f(n) << endl;
  return 0;
}
