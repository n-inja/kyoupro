#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  reverse(v.begin(), v.end());
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += v[i];
  bool b = false;
  if (sum % 2 == 1) {
    b = true;
    for (int i = 0; i <= n; i++) {
      if (i < n && v[i] != v[0]) {
        v[i - 1]--;
        break;
      } else if (i == n - 1) {
        v[n - 1]--;
      }
    }
  }

  long long vs = 0, mdis = 0;
  for (long long i = 0; i < n; i++)
    mdis += min(v[i], i + 1);
  for (long long i = 0; i < n; i++) {
    vs += v[i];
    mdis -= min(v[i], i + 1);
    if (vs > i * (i + 1) + mdis) {
      cout << "ABSOLUTELY NO" << endl;
      return 0;
    }
  }
  if (b)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
