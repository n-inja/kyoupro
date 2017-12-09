#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

string andStr(const string &lhs, const string &rhs) {
  string ret;
  for(int i = 0; i < lhs.size(); i++) {
    if(lhs[i] == rhs[i] && lhs[i] == '1') ret.push_back('1');
    else ret.push_back('0');
  }
  return ret;
}

string notStr(const string &s) {
  string ret;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') ret.push_back('1');
    else ret.push_back('0');
  }
  return ret;
}

string xorStr(const string &lhs, const string &rhs) {
  string ret;
  for(int i = 0; i < lhs.size(); i++) {
    if(lhs[i] == rhs[i]) ret.push_back('0');
    else ret.push_back('1');
  }
  return ret;
}

char f(int n) {
  if(n < 10) return '0' + n;
  n -= 10;
  return 'A' + n;
}

bool solve() {
  int n, m, q;
  cin >> n >> m >> q;
  if(n == 0) return false;
  vector<pair<string, string>> s(q), t(q + 1);
  char ans[m + 1] = {0};
  for(int i = 0; i < m; i++) ans[i] = '!';

  for(int i = 0; i < q; i++) cin >> s[i].first >> s[i].second;

  for(int i = 0; i < n; i++) t[0].first.push_back('0');
  for(int i = 0; i < m; i++) t[0].second.push_back('0');

  for(int i = 0; i < q; i++) {
    t[i + 1].first = xorStr(t[i].first, s[i].first);
    t[i + 1].second = s[i].second;
  }
  q++;

  for(int i = 0; i < n; i++) {
    string b;
    for(int j = 0; j < m; j++) b.push_back('1');
    for(int j = 0; j < q; j++) {
      if(t[j].first[i] == '1') b = andStr(b, t[j].second);
      else b = andStr(b, notStr(t[j].second));
    }
    for(int j = 0; j < m; j++) {
      if(b[j] == '1') {
        if(ans[j] == '!') ans[j] = f(i);
        else ans[j] = '?';
      }
    }
  }
  for(int i = 0; i < m; i++) if(ans[i] == '!') ans[i] = '?';
  cout << ans << endl;
  return true;
}

int main() {
  while(solve());
  return 0;
}
