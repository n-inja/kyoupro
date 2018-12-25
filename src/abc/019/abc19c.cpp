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
  const long long BIG = 1073741824;
  int n = 0;
  cin >> n;
  map<long long, bool> mp;
  for(int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    for(long long j = BIG; j > 1; j /= 2) {
      if(a % j == 0) {
        a /= j;
      }
    }
    mp[a] = true;
  }
  cout << mp.size() << endl;
  return 0;
}
