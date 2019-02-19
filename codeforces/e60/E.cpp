#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, q1, q2, q3, a1, a2, a3;
  cin >> s;
  int n = s.size();
  q1 = q2 = q3 = s;
  for (int i = 0; i < n; i++) {
    int j = i / 25, k = i / 25 / 25;
    q1[i] = ('a' + i % 25);
    q2[i] = ('a' + j % 25);
    q3[i] = ('a' + k % 25);
  }
  cout << "? " << q1 << endl;
  cin >> a1;
  cout << "? " << q2 << endl;
  cin >> a2;
  cout << "? " << q3 << endl;
  cin >> a3;
  string ans = s;
  for (int i = 0; i < n; i++) {
    vector<bool> v(n);
    for (int j = 0; j < n; j++) {
      v[j] = v[j] | (a1[j] != q1[i]) | (a2[j] != q2[i]) | (a3[j] != q3[i]);
    }
    int id = 0;
    for (int j = 0; j < n; j++)
      if (!v[j])
        id = j;
    ans[i] = s[id];
  }
  cout << "! " << ans << endl;

  return 0;
}
