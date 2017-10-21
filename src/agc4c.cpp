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
  int h, w;
  cin >> h >> w;
  vector<string> mp(h), red(h), blue(h);
  for(int i = 0; i < h; i++) cin >> mp[i];
  for(int i = 0; i < w; i++) red[0].push_back('#');
  for(int i = 0; i < w; i++) red[h - 1].push_back('.');
  for(int i = 1; i < h - 1; i++) for(int j = 0; j < w; j++) red[i].push_back((j % 2 == 0) ? '#' : '.');
  for(int i = 0; i < w; i++) blue[0].push_back('.');
  for(int i = 0; i < w; i++) blue[h - 1].push_back('#');
  for(int i = 1; i < h - 1; i++) for(int j = 0; j < w; j++) blue[i].push_back((j % 2 == 0) ? '.' : '#');

  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == '#') {
    red[i][j] = '#';
    blue[i][j] = '#';
  }

  for(int i = 0; i < h; i++) cout << red[i] << endl;
  cout << endl;
  for(int i = 0; i < h; i++) cout << blue[i] << endl;

  return 0;
}
