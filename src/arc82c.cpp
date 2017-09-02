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
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
    mp[v[i] - 1]++;
    mp[v[i]]++;
    mp[v[i] + 1]++;
  }
  int id = 0;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    if(mp[id] < it->second) {
      id = it->first;
    }
  }
  cout << mp[id] << endl;
  return 0;
}
