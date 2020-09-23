#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

ll P = 998244353;
ll sdp[401010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector <pair<int, int >> lr(k);
  for (int i = 0; i < k; i++) cin >> lr[i].first >> lr[i].second;
  sdp[0] = 1;
  sdp[1] = -1;
  ll s = 0;
  for (int i = 0; i < n; i++) {
    s = (s + sdp[i]) % P;
    for (int j = 0; j < k; j++) {
      sdp[i + lr[j].first] += s;
      sdp[i + lr[j].second + 1] += P - s;
      sdp[i + lr[j].first] %= P;
      sdp[i + lr[j].second + 1] %= P;
    }
  }
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum = (sum + sdp[i]) % P;
  }
  cout << sum << endl;
  return 0;
}
