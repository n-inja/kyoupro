#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

const long long PRIME = 1000000007;
const double mpi = 3.14159265358979323846;

using namespace std;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if(H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  }
  bool b = H % h == 0;
  if(b) {
    vector<int> v(W + 1), c(W);
    for(int i = w; i < W + 1; i += w) v[i] = v[i - w] - 1;
    v[W] = 1;
    for(int i = W - w; i >= 0; i -= w) v[i] = v[i + w] + 1;
    for(int i = 1; i <= w; i++) {
      for(int j = i + w; j < W + 1; j++) v[j] = v[j - w] - 1;
    }
    for(int i = 0; i < W; i++) c[i] = v[i + 1] - v[i];
    cout << "Yes" << endl;
    for(int i = 0; i < H; i++) {
      cout << c[0];
      for(int j = 1; j < W; j++) cout << " " << c[j];
      cout << endl;
    }
  } else {
    vector<int> v(H + 1), c(H);
    for(int i = h; i < H + 1; i += h) v[i] = v[i - h] - 1;
    v[H] = 1;
    for(int i = H - h; i >= 0; i -= h) v[i] = v[i + h] + 1;
    for(int i = 1; i <= h; i++) {
      for(int j = i + h; j < H + 1; j++) v[j] = v[j - h] - 1;
    }
    for(int i = 0; i < H; i++) c[i] = v[i + 1] - v[i];
    cout << "Yes" << endl;
    for(int i = 0; i < H; i++) {
      cout << c[i];
      for(int j = 1; j < W; j++) cout << " " << c[i];
      cout << endl;
    }
  }
  return 0;
}
