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
  vector<long long> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  set<long long> s;
  for(int i = 0; i < n; i++) {
    long long m = 0;
    for(int j = i; j < n && j - i < 15; j++) {
      m *= 10;
      m += d[j];
      s.insert(m);
    }
  }
  if(s.find(0) == s.end()) {
    cout << 0 << endl;
    return 0;
  }
  s.insert(10000000000000000);
  long long old = -1;
  for(auto it = s.begin(); it != s.end(); it++) {
    if(*it - old > 1) {
      cout << old + 1 << endl;
      return 0;
    }
    old = *it;
  }
  return 0;
}
