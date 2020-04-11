#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool includeEq(string &l, string &r, bool mode) {
  if (mode) {
    for (int i = 0; i < l.size() && i < r.size(); i++) {
      if (r[r.size() - 1 - i] == '*') return true;
      if (l[l.size() - 1 - i] != r[r.size() - 1 - i]) return false;
    }
    return true;
  } else {
    for (int i = 0; i < l.size() && i < r.size(); i++) {
      if (r[i] == '*') return true;
      if (l[i] != r[i]) return false;
    }
    return true;
  }
}

string cut(string &s, bool mode) {
  string ret;
  if (mode) {
    for (int i = 0; i < s.size(); i++) {
      if (s[s.size() - 1 - i] == '*') break;
      ret.push_back(s[s.size() - 1 - i]);
    }
    reverse(ret.begin(), ret.end());
  } else {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') break;
      ret.push_back(s[i]);
    }
  }
  return ret;
}

string icut(string &s) {
  string ret;
  int i = 0;
  int j = s.size() - 1;
  for (; i < s.size(); i++) {
    if (s[i] == '*') break;
  }
  for (; j >= 0; j--) {
    if (s[j] == '*') break;
  }
  for (int k = i; k < j; k++) {
    if (s[k] == '*') continue;
    ret.push_back(s[k]);
  }
  return ret;
}

void solve(int t) {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  string left, right;
  bool hasLeft = false, hasRight = false;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (v[i][0] != '*') {
      if (hasLeft) {
        if (!includeEq(left, v[i], false)) {
          ok = false;
        } else {
          string nleft = cut(v[i], false);
          if (left.size() < nleft.size()) {
            swap(left, nleft);
          }
        }
      } else {
        hasLeft = true;
        left = cut(v[i], false);
      }
    }
    if (v[i].back() != '*') {
      if (hasRight) {
        if (!includeEq(right, v[i], true)) {
          ok = false;
        } else {
          string nright = cut(v[i], true);
          if (right.size() < nright.size()) {
            swap(right, nright);
          }
        }
      } else {
        hasRight = true;
        right = cut(v[i], true);
      }
    }
  }
  if (!ok) {
    cout << "Case #" << t << ": *" << endl;
    return;
  }
  vector<string> ans;
  ans.push_back(left);
  for (int i = 0; i < n; i++) {
    ans.push_back(icut(v[i]));
  }
  ans.push_back(right);
  cout << "Case #" << t << ": ";
  for (auto &s : ans) cout << s;
  cout << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
