#include<iostream>
#include<vector>

using namespace std;

int main() {
  long long n, m, q;
  cin >> n >> m;
  vector<long long> v(n);
  v[0] = 1;
  cout << v[0];
  for(long long i = 1; i < n; i++) {
    v[i] = v[i - 1] + i;
    cout << " " << v[i];
  }
  cin >> q;
  for(long long i = 0; i < q; i++) {
    long long x;
    cin >> x;
    
  }
}

int main() {
  int n = 200000;
  long long m = 1000000000000;
  vector<long long> v(n);
  v[0] = 1;
  for(long long i = 1; i < n; i++) v[i] = v[i - 1] + i;
  map<long long, bool> mp;
  for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
    if(mp[v[i] + v[j]]) {
      cout << "No" << endl;
      return 0;
    }
    mp[v[i] + v[j]] = true;
  }
  cout << "Yes" << endl;
  return 0;
}