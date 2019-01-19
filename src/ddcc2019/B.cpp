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
  ll n, k, r;
  cin >> n >> k >> r;
  vector<int> ans;
  ll sum = 0;
  int i = 0;
  for (; i < n; i++) {
    int paths = max(0LL, i - k + 1);
    if (sum + paths < r) {
      ans.push_back(i);
      sum += paths;
    } else {
      ans.push_back(i);
      int p = ans.size() - 1;
      int q = p - (sum + paths - r + k - 1);
      if (q < 0)
        q = 0;
      for (int j = p; j > q; j--) {
        swap(ans[j], ans[j - 1]);
      }
      sum = r;
      i++;
      break;
    }
  }
  if (sum < r) {
    cout << "No Luck" << endl;
    return 0;
  }
  reverse(ans.begin(), ans.end());
  for (; i < n; i++)
    ans.push_back(i);
  cout << ans[0] + 1;
  for (int i = 1; i < n; i++)
    cout << " " << ans[i] + 1;
  cout << endl;

  return 0;
}
