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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++)
    cin >> l[i] >> r[i];
  vector<int> sum(n + 4);
  sum[0] = 0;
  for (int i = 0; i < m; i++) {
    sum[l[i]]++;
    sum[r[i] + 1]--;
  }
  int ans = 0, s = 0;
  for (int i = 0; i < n; i++) {
    s += sum[i + 1];
    if (s == 0)
      ans++;
  }
  cout << (n - ans) * a + ans * b << endl;

  return 0;
}
