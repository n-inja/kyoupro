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
  string s;
  cin >> s;
  vector<int> v;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s[i] - '0');
    ans += s[i] - '0';
  }

  int core = 0;
  for (int i = 0; i < v.size(); i++) {
    int sum = core + v[i] - 1;
    sum += 9 * (v.size() - (i + 1));
    ans = max(ans, sum);
    core += v[i];
  }
  cout << ans << endl;
  return 0;
}
