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

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  long long ans = 0;
  sort(p.begin(), p.end());
  for (int i = 0; i < n - 1; i++)
    ans += p[i];
  ans += p[n - 1] / 2;
  cout << ans << endl;
  return 0;
}
