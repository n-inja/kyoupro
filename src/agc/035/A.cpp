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
  for (int i = 0; i < n; i++) cin >> a[i];

  if (n % 3 == 1) {
    map<ll, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    if ((mp.size() == 2 && mp[0] == n / 3) || (n == mp[0])) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (n % 3 == 2) {
    bool ok = true;
    for (int i = 0; i < n; i++) if (a[i] > 0) ok = false;
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    map<ll, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    vector<ll> v;
    for (auto &pr : mp) v.push_back(pr.first);
    if (v.size() > 3) {
      cout << "No" << endl;
    } else if (mp[0] == n || (mp[0] * 3 == n && mp.size() == 2)) {
      cout << "Yes" << endl;
    } else if (v.size() == 3 && mp[v[0]] == mp[v[1]] && mp[v[1]] == mp[v[2]] && ((v[0] ^ v[1] ^ v[2]) == 0)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
