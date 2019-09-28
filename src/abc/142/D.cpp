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
  ll a, b;
  cin >> a >> b;
  map<ll, int> amp, bmp;
  ll aa = a, bb = b;
  for (ll i = 2; i * i <= aa; i++) {
    while (aa % i == 0) {
      amp[i]++;
      aa /= i;
    }
  }
  for (ll i = 2; i * i <= bb; i++) {
    while (bb % i == 0) {
      bmp[i]++;
      bb /= i;
    }
  }
  if (aa > 1) amp[aa]++;
  if (bb > 1) bmp[bb]++;
  map<ll, int> mp;
  for (auto &it : amp) {
    if (bmp.find(it.first) != bmp.end()) {
      mp[it.first] = min(it.second, bmp[it.first]);
    }
  }

  cout << mp.size() + 1 << endl;

  return 0;
}
