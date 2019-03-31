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
  vector<int> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) v[i]--;

  long long ans = 0;
  for(int i = 0; i < n; i++) {
    while(v[i] != i) {
      swap(v[i], v[v[i]]);
      ans++;
    }
  }
  if((ans % 2) ^ (n % 2)) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
