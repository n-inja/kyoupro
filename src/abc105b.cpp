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
  bool dp[101] = {0};
  dp[0] = true;
  for (int i = 0; i < 101; i++) {
    if (i - 4 >= 0)
      dp[i] |= dp[i - 4];
    if (i - 7 >= 0)
      dp[i] |= dp[i - 7];
  }
  if (dp[n])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
