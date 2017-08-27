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

int dist(int a, int b) {
  if(a == b) return 0;
  if(a > b) swap(a, b);
  cout << "? " << a << " " << b << endl;
  int ret;
  cin >> ret;
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for(int i = 1; i < n; i++) d[i] = dist(1, i + 1);
  int id = 0;
  for(int i = 0; i < n; i++) if(d[id] < d[i]) id = i;
  int ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, dist(id + 1, i + 1));
  cout << "! " << ans << endl;
  return 0;
}
