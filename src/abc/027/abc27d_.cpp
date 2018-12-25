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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v;
  int plussum = 0, minussum = 0;
  for(int i = 0; i < n; i++) {
    if(s[n - i - 1] == '+') plussum++;
    if(s[n - i - 1] == '-') minussum++;
    if(s[n - i - 1] == 'M') v.push_back(plussum - minussum);
  }
  sort(v.begin(), v.end());
  int bsum = 0, csum = 0;
  for(int i = 0; i * 2 < v.size(); i++) {
    bsum += v[i];
    csum += v[v.size() - 1 - i];
  }
  cout << csum - bsum << endl;
  return 0;
}
