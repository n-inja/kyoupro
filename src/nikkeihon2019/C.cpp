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
  int h, w, k;
  cin >> h >> w >> k;
  vll wc(w), hc(h), swc(w + 1), shc(h + 1);
  for (int i = 0; i < h; i++)
    hc[i] = w;
  for (int i = 0; i < w; i++)
    wc[i] = h;
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    hc[r]--;
    wc[c]--;
  }
  for (int i = 0; i < h; i++)
    shc[i + 1] = shc[i] + hc[i];
  for (int i = 0; i < w; i++)
    swc[i + 1] = swc[i] + wc[i];
  ll wwc = 0, hhc = 0;
  for (int i = 0; i < w; i++)
    wwc += (i + 1) * wc[i];
  for (int i = 0; i < h; i++)
    hhc += (i + 1) * hc[i];
  ll minw = 1000000000000000000LL;
  for (int i = 0; i < w; i++) {
    wwc -= swc[w] - swc[i];
    wwc += swc[i] - swc[0];
    minw = min(minw, wwc);
  }
  ll minh = 1000000000000000000LL;
  for (int i = 0; i < h; i++) {
    hhc -= shc[h] - shc[i];
    hhc += shc[i] - shc[0];
    minh = min(minh, hhc);
  }
  cout << minh + minw << endl;

  return 0;
}
