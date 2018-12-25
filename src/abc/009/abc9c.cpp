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

#define P 1000000007

using namespace std;

int comp(string s, string t) {
  int ans = 0;
  for(int i = 0; i < s.size(); i++) if(s[i] != t[i]) ans++;
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s;
  t = s;
  sort(t.begin(), t.end());
  if(comp(s, t) <= k) {
    cout << t << endl;
    return 0;
  }
  t = s;
  for(int i = 0; i < n; i++) {
    int id = i;
    for(int j = i+1; j < n; j++) {
      string sn = s;
      sn[j] = s[i];
      sn[i] = s[j];
      if(comp(sn, t) <= k && s[id] > s[j]) {
        id = j;
      }
    }
    char c = s[i];
    s[i] = s[id];
    s[id] = c;
  }
  cout << s << endl;
  return 0;
}
