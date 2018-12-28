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

struct Chains1 {
  long long countMaximalChains(int n) {
    long long dp[60] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
      dp[i + 1] = dp[i] * 2;
    }
    return dp[n];
  }
};

int main() { return 0; }
