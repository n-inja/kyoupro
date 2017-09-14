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
  vector<long long> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  map<long long, int> mp;
  for(int i = 0; i < n; i++) mp[v[i]] = 0;
  int j = 0;
  for(auto it = mp.begin(); it != mp.end(); it++) it->second = j++;
  for(int i = 0; i < n; i++) cout << mp[v[i]] << endl;
  return 0;
}
