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
  set<long long> s;
  for(int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if(s.find(a) == s.end()) s.insert(a);
    else s.erase(s.find(a));
  }
  cout << s.size() << endl;
  return 0;
}
