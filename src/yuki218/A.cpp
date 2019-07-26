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
  int n;
  cin >> n;
  vector<ll> a(n);
  string s;
  getline(cin, s);
  getline(cin, s);
  bool ok = true;
  for (char c : s) if (c == ' ') ok = false;
  if (!ok) {
    cout << "\"assert\"" << endl;
    return 0;
  } else {
    a[0] = stoll(s);
  }
  for (int i = 1; i < n; i++) cin >> a[i];
  set<ll> sum;

  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) sum.insert(a[i] + a[j]);
  auto it = sum.rbegin();
  it++;
  cout << *it << endl;
  return 0;
}
