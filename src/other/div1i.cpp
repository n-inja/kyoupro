#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<pair<long long, long long>> wp;

int main() {
  int n, k;
  cin >> n >> k;
  wp.resize(n);
  for (int i = 0; i < n; i++)
    cin >> wp[i].first >> wp[i].second;

  return 0;
}
