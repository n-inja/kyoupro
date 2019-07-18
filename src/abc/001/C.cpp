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
  int deg;
  double dis;
  cin >> deg >> dis;
  deg *= 10;
  string h = "N";
  if (deg < 1125) {

  } else if (deg < 3375) {
    h = "NNE";
  } else if (deg < 5625) {
    h = "NE";
  } else if (deg < 7875) {
    h = "ENE";
  } else if (deg < 10125) {
    h = "E";
  } else if (deg < 12375) {
    h = "ESE";
  } else if (deg < 14625) {
    h = "SE";
  } else if (deg < 16875) {
    h = "SSE";
  } else if (deg < 19125) {
    h = "S";
  } else if (deg < 21375) {
    h = "SSW";
  } else if (deg < 23625) {
    h = "SW";
  } else if (deg < 25875) {
    h = "WSW";
  } else if (deg < 28125) {
    h = "W";
  } else if (deg < 30375) {
    h = "WNW";
  } else if (deg < 32625) {
    h = "NW";
  } else if (deg < 34875) {
    h = "NNW";
  }

  dis = round(dis / 6) / 10;

  int s = 0;
  if (dis <= 0.2) {
    s = 0;
  } else if (dis <= 1.5) {
    s = 1;
  } else if (dis <= 3.3) {
    s = 2;
  } else if (dis <= 5.4) {
    s = 3;
  } else if (dis <= 7.9) {
    s = 4;
  } else if (dis <= 10.7) {
    s = 5;
  } else if (dis <= 13.8) {
    s = 6;
  } else if (dis <= 17.1) {
    s = 7;
  } else if (dis <= 20.7) {
    s = 8;
  } else if (dis <= 24.4) {
    s = 9;
  } else if (dis <= 28.4) {
    s = 10;
  } else if (dis <= 32.6) {
    s = 11;
  } else {
    s = 12;
  }
  if (s == 0) {
    cout << "C 0" << endl;
    return 0;
  }
  cout << h << " " << s << endl;
  return 0;
}
