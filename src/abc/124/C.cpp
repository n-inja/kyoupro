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
  string s;
  cin >> s;
  string bw, wb;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2) {
      bw.push_back('0');
      wb.push_back('1');
    } else {
      bw.push_back('1');
      wb.push_back('0');
    }
  }
  ll wbc = 0, bwc = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != wb[i])
      wbc++;
    if (s[i] != bw[i])
      bwc++;
  }
  cout << min(bwc, wbc) << endl;
  return 0;
}
