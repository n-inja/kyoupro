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
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  ans = 1;
  int l = 0, r = 0;
  for(r = 1; r < n; r++) {

    if(a[r] <= a[r - 1]) l = r;
    ans += (r - l + 1);
  }
  cout << ans << endl;

  return 0;
}
