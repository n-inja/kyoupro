#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string a, b;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '4') {
        a.push_back('2');
        b.push_back('2');
      } else {
        a.push_back(s[j]);
        b.push_back('0');
      }
    }
    int id = 0;
    for (int j = 0; j < b.size(); j++)
      if (b[j] != '0') {
        id = j;
        break;
      }
    if (id > 0)
      b = b.substr(id, b.size() - id);
    cout << "Case #" << i + 1 << ": " << a << " " << b << endl;
  }
  return 0;
}
