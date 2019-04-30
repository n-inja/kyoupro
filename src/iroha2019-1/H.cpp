#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  bool cor = true;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != '9')
      cor = false;
  if (cor || s.size() == 1) {
    cout << 1;
    s[0] -= 1;
    cout << s << endl;
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
    sum += s[i] - '0';
  string t;
  while (sum) {
    int a = min(9, sum);
    sum -= a;
    t.push_back('0' + a);
  }
  reverse(t.begin(), t.end());
  if (t == s) {
    t[0] += 1;
    t[1] -= 1;
  }
  cout << t << endl;
  return 0;
}
