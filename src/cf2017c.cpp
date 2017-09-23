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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i < h; i++) cin >> s[i];
  vector<char> c;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) c.push_back(s[i][j]);
  sort(c.begin(), c.end());
  int a1 = 0, a2 = 0, a4 = 0;
  map<char, int> mp;
  for(int i = 0; i < c.size(); i++) mp[c[i]]++;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    a4 += it->second / 4;
    it->second %= 4;
    if(it->second > 1) {
      a2++;
      it->second -= 2;
    }
    if(it->second > 0) {
      a1++;
      it->second = 0;
    }
  }
  bool b = false;
  if(h % 2 == 1 && w % 2 == 1) {
    if(a4 >= (h - 1) * (w - 1) / 4) {
      a4 -= (h - 1) * (w - 1) / 4;
      a2 += a4 * 2;
      if(a2 >= (h + w - 2) / 2) {
        a2 -= (h + w - 2) / 2;
        a1 += a2 * 2;
        if(a1 >= 1) {
          b = true;
        }
      }
    }
  } else if(h % 2 == 0 && w % 2 == 0) {
    if(a4 >= h * w / 4) {
      b = true;
    }
  } else {
    if(h % 2 == 1) swap(h, w);
    // w % 2 == 1
    if(a4 >= (w - 1) * h / 4) {
      a4 -= (w - 1) * h / 4;
      a2 += a4 * 2;
      if(a2 >= h / 2) {
        b = true;
      }
    }
  }
  if(b) cout << "Yes" << endl;
  else cout << "No" << endl;
	return 0;
}
