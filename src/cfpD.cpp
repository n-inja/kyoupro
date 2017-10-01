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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int n = s1.size();
  map<char, int> ss1, ss2, ss3;
  for(int i = 0; i < n; i++) {
    ss1[s1[i]]++;
    ss2[s2[i]]++;
    ss3[s3[i]]++;
  }
  int c1 = 0, c2 = 0;
  for(auto it = ss3.begin(); it != ss3.end(); it++) {
    while(ss1[it->first] < it->second || ss2[it->first] < it->second) {
      if(ss1[it->first] < it->second) {
        int d = it->second - ss1[it->first];
        ss2[it->first] -= d;
        c2 += d;
        it->second -= d;
      } else if(ss2[it->first] < it->second) {
        int d = it->second - ss2[it->first];
        ss1[it->first] -= d;
        c1 += d;
        it->second -= d;
      }
    }
  }
  if(c1 <= n / 2 && c2 <= n / 2) cout << "YES" << endl;
  else cout << "NO" << endl;
	return 0;
}
