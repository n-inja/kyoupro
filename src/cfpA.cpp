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
  map<char, int> mp;
  for(int i = 0; i < s.size(); i++) mp[s[i]]++;
  string ans = "";
  for(auto it = mp.begin(); it != mp.end(); it++) {
    ans.push_back(it->first);
    ans.push_back(it->first);
  }
  cout << ans << endl;
	return 0;
}
