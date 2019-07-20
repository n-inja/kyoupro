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
  int h, w;
  cin >> h >> w;
  cout << string(w + 2, '#') << endl;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    cout << "#" << s << "#" << endl;
  }
  cout << string(w + 2, '#') << endl;
  return 0;
}
