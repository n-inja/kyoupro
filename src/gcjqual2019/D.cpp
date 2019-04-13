#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

string query[] = {
    "0000000011111111",
    "0000111100001111",
    "0011001100110011",
    "0101010101010101",
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int l = 1; l <= T; l++) {
    int n, b, f;

    cin >> n >> b >> f;
    int m = n - b;
    string q, a;
    for (int i = 0; i < n; i++) {
      q.push_back("01"[(i / 16) % 2]);
    }
    cout << q << endl;
    cin >> a;
    vi inv(m), zipped;
    int c = 0, isZ = true;
    for (int i = 0; i < m; i++) {
      if (isZ) {
        if (a[i] == '0') {
          c++;
        } else {
          zipped.push_back(c);
          isZ = false;
          c = 1;
        }
      } else {
        if (a[i] == '1') {
          c++;
        } else {
          zipped.push_back(c);
          isZ = true;
          c = 1;
        }
      }
    }
    zipped.push_back(c);
    c = 0;
    for (int i = 0; i < zipped.size(); i++) {
      for (int j = 0; j < zipped[i]; j++)
        inv[c++] = i * 16;
    }
    string ans[4];
    for (int i = 0; i < 4; i++) {
      q = "";
      for (int j = 0; j < (n + 15) / 16; j++)
        q += query[i];
      cout << q.substr(0, n) << endl;
      cin >> ans[i];
    }
    vector<bool> ok(n);
    for (int i = 0; i < m; i++) {
      ok[inv[i] + (ans[0][i] - '0') * 8 + (ans[1][i] - '0') * 4 +
         (ans[2][i] - '0') * 2 + (ans[3][i] - '0')] = true;
    }
    vector<int> ids;
    for (int i = 0; i < n; i++)
      if (!ok[i])
        ids.push_back(i);
    cout << ids[0];
    for (int i = 1; i < ids.size(); i++)
      cout << " " << ids[i];
    cout << endl;
    int collect;
    cin >> collect;
    if (collect == -1) {
      break;
    }
  }

  return 0;
}
