#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int num[26];
};

string toS(Node &n) {
  string ret = "";
  for (int i = 0; i < 26; i++) {
    string ss = to_string(n.num[i]);
    for (int j = 0; j < 5 - ss.size(); j++)
      ret.push_back('0');
    ret += ss;
  }
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  map<string, int> mp;

  Node node;
  for (int i = 0; i < 26; i++)
    node.num[i] = 0;
  for (int i = 0; i < k; i++)
    node.num[s[i] - 'a']++;
  mp[toS(node)] = 1;
  for (int i = 1; i < n - k + 1; i++) {
    node.num[s[i - 1] - 'a']--;
    node.num[s[i + k - 1] - 'a']++;
    if (mp[toS(node)] > 0) {
      if (i - (mp[toS(node)] - 1) >= k) {
        cout << "YES" << endl;
        return 0;
      }
    } else {
      mp[toS(node)] = i + 1;
    }
  }
  cout << "NO" << endl;
  return 0;
}
