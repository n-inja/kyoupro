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
  string s;
  cin >> s;
  long long ans = s.size() * (s.size() + 1) / 2;
  map<char, int> sum;
  for(int i = 0; i < s.size(); i++) {
  sum[s[i]]++;
    ans -= sum[s[i]];
  }
  cout << ans + 1 << endl;
  return 0;
}
