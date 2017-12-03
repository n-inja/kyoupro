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

using namespace std;

int main() {
  string s;
  cin >> s;
  int sum[3] = {0, 0, 0};
  for(int i = 0; i < s.size(); i++) sum[s[i] - 'a']++;
  int mi = min(min(sum[0], sum[1]), sum[2]);
  int ma = max(max(sum[0], sum[1]), sum[2]);
  if(ma - mi < 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
