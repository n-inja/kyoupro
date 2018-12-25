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
  vector<int> imos(1000002, 0);
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    imos[a] += 1;
    imos[b + 1] -= 1;
  }
  int ans = 0, sum = 0, id = 0;
  for(int i = 0; i < 1000001; i++) {
    sum += imos[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
