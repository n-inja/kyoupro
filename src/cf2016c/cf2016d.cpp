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

using namespace std;
void rdfs(int id, long long val);
void cdfs(int id, long long val);

vector<bool> rc, cc;
int r, c, n;
vector<vector<pair<int, long long>>> rp, cp;
vector<long long> rw, cw;
bool b = false;
long long rmin = 1000000000000, cmin = 10000000000000;

void rdfs(int id, long long val) {
  rmin = min(rmin, val);
  if(rc[id]) {
    if(rw[id] != val) b = true;
    return;
  } else {
    rc[id] = true;
    rw[id] = val;
  }
  for(int i = 0; i < rp[id].size(); i++) {
    cdfs(rp[id][i].first, rp[id][i].second - val);
  }
}

void cdfs(int id, long long val) {
  cmin = min(cmin, val);
  if(cc[id]) {
    if(cw[id] != val) b = true;
    return;
  } else {
    cc[id] = true;
    cw[id] = val;
  }
  for(int i = 0; i < cp[id].size(); i++) {
    rdfs(cp[id][i].first, cp[id][i].second - val);
  }
}

int main() {
  cin >> r >> c >> n;
  rw.resize(r); cw.resize(c);
  rp.resize(r); cp.resize(c);
  for(int i = 0; i < n; i++) {
    long long r1, c1, a;
    cin >> r1 >> c1 >> a;
    r1--; c1--;
    rp[r1].push_back(make_pair(c1, a));
    cp[c1].push_back(make_pair(r1, a));
  }
  rc.resize(r); cc.resize(c);
  for(int i = 0; i < r; i++) if(!rc[i]) {
    rmin = 100000000000; cmin = 100000000000;
    rdfs(i, 0);
    if(rmin + cmin < 0) b = true;
  }
  for(int i = 0; i < c; i++) if(!cc[i]) {
    rmin = 100000000000; cmin = 100000000000;
    cdfs(i, 0);
    if(rmin + cmin < 0) b = true;
  }
  if(b) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

	return 0;
}
