#include <algorithm>
#include <bitset>
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
int n;
vector<int> a;
bitset<4004000> bs;

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  bs.set(0);
  for (int i = 0; i < n; i++) {
    bs |= bs << a[i];
  }
  for (int i = (sum + 1) / 2; i <= sum; i++) {
    if (bs[i]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
