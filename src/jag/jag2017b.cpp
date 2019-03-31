#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

vector<int> v(26);

void end() {
  cout << "No" << endl;
  exit(0);
}

char match(char c1, char c2) {
  if(v[c1 - 'a'] == 0 && v[c2 - 'a'] == 0) end();
  if(v[c1 - 'a'] > 0 && v[c2 - 'a'] > 0) end();
  if(v[c1 - 'a'] == 0) {
    v[c2 - 'a']--;
    return c2;
  } else {
    v[c1 - 'a']--;
    return c1;
  }
}

void f(string s) {
  if(s.size() == 1) return;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '-' && s[i - 2] == '[' && s[i + 2] == ']') {
      char win = match(s[i - 1], s[i + 1]);
      string next = s.substr(0, i - 2);
      next.push_back(win);
      next += s.substr(i + 3, s.size());
      f(next);
      return;
    }
  }
}

int main() {
  string s;
  cin >> s;
  int n = 0;
  bool check[26] = {0};
  for(int i = 0; i < s.size(); i++) if(s[i] >= 'a' && s[i] <= 'z') check[s[i] - 'a'] = true;
  for(int i = 0; i < 26; i++) if(check[i]) n++;
  for(int i = 0; i < n; i++) {
    char c;
    cin >> c;
    cin >> v[c - 'a'];
  }

  f(s);
  sort(v.begin(), v.end());
  if(v[25] == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
