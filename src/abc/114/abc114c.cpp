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
  int ans = 0, n;
  cin >> n;
  vector<int> v;
  int a[3] = {3, 5, 7};
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 8 - i; j++)
      for (int k = 1; k <= 9 - i - j; k++) {
        v.clear();
        for (int l = 0; l < i; l++)
          v.push_back(0);
        for (int l = 0; l < j; l++)
          v.push_back(1);
        for (int l = 0; l < k; l++)
          v.push_back(2);
        do {
          long long num = 0;
          for (int l = 0; l < v.size(); l++) {
            num *= 10;
            num += a[v[l]];
          }
          if (num <= n)
            ans++;
        } while (next_permutation(v.begin(), v.end()));
      }
  cout << ans << endl;
  return 0;
}
