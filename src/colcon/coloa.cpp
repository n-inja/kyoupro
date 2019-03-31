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
  int a, b;
  string s;

  cin >> a >> b >> s;
  if(a <= s.size() && s.size() <= b) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
