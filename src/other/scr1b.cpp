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

const long long PRIME = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int b;
    cin >> b;
    ans += b;
  }
  cout << ans << endl;
  return 0;
}