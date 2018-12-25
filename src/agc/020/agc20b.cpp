#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

int main() {
  int k;
  cin >> k;
  vector<long long> a(k);
  for(int i = 0; i < k; i++) cin >> a[i];
  long long minDP[k + 1];
  long long maxDP[k + 1];
  minDP[0] = 2;
  maxDP[0] = 2;
  for(int i = 0; i < k; i++) {
    if(maxDP[i] < a[k - 1 - i]) {
      cout << -1 << endl;
      return 0;
    }
    minDP[i + 1] = max((minDP[i] + a[k - 1 - i] - 1) / a[k - 1 - i] * a[k - 1 - i], a[k - 1 - i]);
    maxDP[i + 1] = maxDP[i] / a[k - 1 - i] * a[k - 1 - i] + a[k - 1 - i] - 1;
    if(minDP[i + 1] > maxDP[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << minDP[k] << " " << maxDP[k] << endl;
  return 0;
}
