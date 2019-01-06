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
vector<vector<long long>> memo1, memo2;
vector<int> a;
long long INF = 1000000000000000000LL;

long long jiro(int, int);
long long taro(int st, int ls) {
  if (memo1[st][ls] != -INF)
    return memo1[st][ls];
  if (st + ls >= n)
    return 0;
  return memo1[st][ls] =
             max(jiro(st + 1, ls) + a[st], jiro(st, ls + 1) + a[n - 1 - ls]);
}

long long jiro(int st, int ls) {
  if (memo2[st][ls] != -INF)
    return memo2[st][ls];
  if (st + ls >= n)
    return 0;
  return memo2[st][ls] =
             min(taro(st + 1, ls) - a[st], taro(st, ls + 1) - a[n - 1 - ls]);
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  memo1.resize(n + 1);
  memo2.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    memo1[i].resize(n + 1);
    memo2[i].resize(n + 1);
    for (int j = 0; j <= n; j++)
      memo1[i][j] = memo2[i][j] = -INF;
  }
  cout << taro(0, 0) << endl;
  return 0;
}
