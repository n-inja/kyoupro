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
  int n = s.size();
  int m = n / 2;
  int cnt[3] = {0};
  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
  for (int i = 0; i < 3; i++) {
    if (cnt[i] >= m) {
      cout << string(cnt[i], 'a' + i) << endl;
      return 0;
    }
  }
  string ans;
  vector<vector<int>> select(3, vector<int>(n));
  for (int i = 0; i < n; i++) select[s[i] - 'a'].push_back(i);
  int j = n - 1;
  string sub;
  for (int i = 0; i < j;) {
    if (s[i] == s[j]) {
      ans.push_back(s[i]);
      i++;
      j--;
    } else if (s[i + 1] == s[j]) {
      if (i + 1 == j) {
        sub.push_back(s[i + 1]);
        break;
      }
      ans.push_back(s[i + 1]);
      i += 2;
      j--;
    } else if (s[i] == s[j - 1]) {
      if (i == j - 1) {
        sub.push_back(s[i + 1]);
        break;
      }
      ans.push_back(s[i]);
      i++;
      j -= 2;
    } else if (s[i + 1] == s[j - 1]) {
      if (i + 1 == j - 1) {
        sub.push_back(s[i + 1]);
        break;
      }
      ans.push_back(s[i + 1]);
      i += 2;
      j -= 2;
    }
  }

  string ansr = ans;
  reverse(ansr.begin(), ansr.end());
  cout << ans << sub << ansr << endl;

  return 0;
}
