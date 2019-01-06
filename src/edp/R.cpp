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

long long P = 1000000007;
void mul(vector<vector<long long>> &a, vector<vector<long long>> &b,
         vector<vector<long long>> &c) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % P;
        c[i][j] %= P;
      }
    }
  }
}

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<vector<long long>> a, b, ans;
  a.resize(n);
  b.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n);
    b[i].resize(n);
    ans[i].resize(n);
    ans[i][i] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  while (k > 0) {
    if (k % 2 == 0) {
      mul(a, a, b);
      swap(a, b);
    } else {
      mul(a, ans, b);
      swap(ans, b);
      mul(a, a, b);
      swap(a, b);
    }
    k >>= 1;
  }
  long long ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ret += ans[i][j];
      ret %= P;
    }
  cout << ret << endl;
  return 0;
}
