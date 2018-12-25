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

#define P 1000000007

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int r, l;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
