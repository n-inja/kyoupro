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
  long long n;
  cin >> n;
  vector<long long> ans;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  ans.push_back(n * (n + 1) / 2);
  ans.push_back(1);
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long sum = 0;
      int c = 0;
      sum = (n / i) * (2 + (n / i - 1) * i) / 2;
      ans.push_back(sum);
      if (i * i != n) {
        sum = 0;
        c = 0;
        sum = i * (2 + (i - 1) * (n / i)) / 2;
        ans.push_back(sum);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}
