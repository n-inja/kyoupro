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
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  long long ans = 0, sum = 0;
  for(int i = 0; i < k; i++) sum += v[i];
  ans += sum;
  for(int i = k; i < n; i++) {
    sum += v[i];
    sum -= v[i - k];
    ans += sum;
  }
  cout << ans << endl;

  return 0;
}
