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
  int h, w, q;
  cin >> w >> h >> q;
  vector<pair<int, int>> hb, wb;
  for (int i = 0; i < q; i++) {
    int t, d, x;
    cin >> t >> d >> x;
    if (d == 0) {
      wb.emplace_back(-t, x - 1);
    } else {
      hb.emplace_back(-t, x - 1);
    }
  }
  sort(hb.begin(), hb.end());
  sort(wb.begin(), wb.end());
  vector<ll> hv(h), wv(w);
  ll INF = (1LL << 40);

  int befp = -1;
  for (int i = 0; i < hb.size(); i++) {
    if (i + 1 < hb.size() && hb[i].first == hb[i + 1].first && hb[i].second + 1 == hb[i + 1].second) {
      if (befp < 0) {
        befp = hb[i].second;
      }
      continue;
    } else {
      if (befp < 0) {
        befp = hb[i].second;
      }
      ll lv = INF, rv = INF;
      if (befp > 0) {
        lv = hv[befp - 1];
      }
      if (hb[i].second + 1 < h) {
        rv = hv[hb[i].second + 1];
      }
      for (int j = befp; j <= hb[i].second; j++) {
        hv[j] = min(lv + (j - befp + 1), rv + (hb[i].second - j + 1));
      }
      befp = -1;
    }
  }
  befp = -1;
  for (int i = 0; i < wb.size(); i++) {
    if (i + 1 < wb.size() && wb[i].first == wb[i + 1].first && wb[i].second + 1 == wb[i + 1].second) {
      if (befp < 0) {
        befp = wb[i].second;
      }
      continue;
    } else {
      if (befp < 0) {
        befp = wb[i].second;
      }
      ll lv = INF, rv = INF;
      if (befp > 0) {
        lv = wv[befp - 1];
      }
      if (wb[i].second + 1 < w) {
        rv = wv[wb[i].second + 1];
      }
      for (int j = befp; j <= wb[i].second; j++) {
        wv[j] = min(lv + (j - befp + 1), rv + (wb[i].second - j + 1));
      }
      befp = -1;
    }
  }
  ll wmin = wb.size() > 0 ? INF : 0, hmin = hb.size() > 0 ? INF : 0;
  for (int i = 0; i < h; i++) hmin = min(hmin, hv[i]);
  for (int i = 0; i < w; i++) wmin = min(wmin, wv[i]);

  if (wmin + hmin >= INF) {
    cout << -1 << endl;
  } else {
    cout << wmin + hmin << endl;
  }

  return 0;
}
