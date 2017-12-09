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
  long long x;
  cin >> n >> x;
  string s;
  cin >> s;
  vector<long long> t(n);
  for(int i = 0; i < n; i++) cin >> t[i];

  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') ans += min(t[i], x);
    else ans += t[i];
  }
  cout << ans << endl;
  return 0;
}
