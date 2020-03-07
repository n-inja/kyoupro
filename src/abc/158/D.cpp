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
  string s, pre, post;
  cin >> s;
  bool rev = false;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      rev = !rev;
      swap(pre, post);
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        pre.push_back(c);
      } else {
        post.push_back(c);
      }
    }
  }
  if (rev) reverse(s.begin(), s.end());
  reverse(pre.begin(), pre.end());
  cout << pre << s << post << endl;
  return 0;
}
