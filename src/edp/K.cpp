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
int n, k;
vector<int> a;
vector<bool> tdp, jdp;

int main() {
  cin >> n >> k;
  a.resize(n);
  tdp.resize(k + 1);
  jdp.resize(k + 1);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (i + a[j] > k)
        continue;
      if (!tdp[i]) {
        jdp[i + a[j]] = true;
      }
      if (!jdp[i]) {
        tdp[i + a[j]] = true;
      }
    }
  }
  if (tdp[k]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
