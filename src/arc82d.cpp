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
  vector<int> v(n);
  vector<bool> b(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) if(v[i] == i + 1) b[i] = true;
  int ans = 0;
  for(int i = 0; i < n - 1; i++) {
    if(b[i] && b[i + 1]) {
      b[i] = false;
      b[i + 1] = false;
      ans++;
    } else if(b[i]) {
      b[i] = false;
      ans++;
    }
  }
  if(b[n - 1]) ans++;
  cout << ans << endl;
  return 0;
}
