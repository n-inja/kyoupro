#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  int a, b, i;
};

bool operator<(const N &l, const N &r) {
  return l.b > r.b;
}

vector<N> pps, mps;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      pps.push_back(N{a, b, i});
    } else {
      mps.push_back(N{a, -b, i});
    }
  }
  sort(pps.begin(), pps.end());
  sort(mps.begin(), mps.end());
  if (pps.size() > mps.size()) {
    cout << pps.size() << endl;
    cout << pps[0].i + 1;
    for (int i = 1; i < pps.size(); i++) cout << " " << pps[i].i + 1;
    cout << endl;
  } else {
    cout << mps.size() << endl;
    cout << mps[0].i + 1;
    for (int i = 1; i < mps.size(); i++) cout << " " << mps[i].i + 1;
    cout << endl;
  }
  return 0;
}
