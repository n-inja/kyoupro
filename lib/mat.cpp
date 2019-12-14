#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

using BS = bitset<700>;

// return (x, y) (a * x + b * y = gcd(a, b))
pair<long long, long long> exeuclid(long long a, long long b) {
  if (b == 0)
    return make_pair(1, 0);
  pair<long long, long long> ret = exeuclid(b, a % b);
  ret.first -= a / b * ret.second;
  return make_pair(ret.second, ret.first);
}

ll mod_inv(ll a, ll b) {
  return (exeuclid(a, b).first % b + b) % b;
}

int bit_gauss(vector<BS> &a, int m) {
  int rank = 0;
  int n = a.size();
  for (int j = 0; j < min(n, m); j++) {
    for (int i = rank; i < n; i++) {
      if (a[i][j]) {
        for (int k = 0; k < n; k++) {
          if (i == k || !a[k][j]) continue;
          a[k] ^= a[i];
        }
        if (rank != i) {
          swap(a[rank], a[i]);
        }
        rank++;
        break;
      }
    }
  }
  return rank;
}

int mod_gauss(vvl &a, ll mod) {
  int rank = 0;
  for (auto &v : a)
    for (auto &i : v) {
      i %= mod;
      i += mod;
      i %= mod;
    }
  int n = a.size();
  int m = a[0].size();
  for (int j = 0; j < min(n, m); j++) {
    for (int i = rank; i < n; i++) {
      if (a[i][j]) {
        ll inv = mod_inv(a[i][j], mod);
        for (int k = 0; k < m; k++) a[i][k] = (a[i][k] * inv) % mod;
        for (int k = 0; k < n; k++) {
          if (i == k || a[k][j] == 0) continue;
          ll mul = (mod - a[k][j]) % mod;
          for (int l = 0; l < m; l++) a[k][l] = (a[k][l] + a[i][l] * mul) % mod;
        }
        if (rank != i) {
          swap(a[rank], a[i]);
        }
        rank++;
        break;
      }
    }
  }
  return rank;
}

int mod_solve(vvl &a, vll &b, vll &ret, ll mod) {
  int n = a.size();
  vvl c = a;
  for (int i = 0; i < n; i++) {
    c[i].push_back(b[i]);
  }
  int rank = mod_gauss(c, mod);
  for (int i = rank; i < n; i++) if (c[i][n]) return -1;
  ret.resize(n);
  for (int i = 0; i < n; i++) ret[i] = c[i][n];
  return rank;
}

int bit_solve(vector<BS> &a, vector<bool> &b, vector<bool> &ret) {
  int n = a.size();
  auto c = a;
  for (int i = 0; i < n; i++) {
    c[i][n] = b[i];
  }
  int rank = bit_gauss(c, n + 1);

  for (int i = rank; i < n; i++) if (c[i][n]) return -1;
  ret.resize(n);
  for (int i = 0; i < n; i++) ret[i] = c[i][n];
  return rank;
}

// problem: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308

bool solve() {
  int m, n, d;
  cin >> m >> n >> d;
  if (n == 0) return false;
  vvl mp(n, vector<ll>(m));
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mp[i][j];
  vector<BS> a(n * m);
  vector<bool> b(n * m);
  auto to_index = [&](int i, int j) {
    return i + j * n;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[to_index(i, j)] = mp[i][j];
      a[to_index(i, j)][to_index(i, j)] = true;
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++) {
          if ((abs(i - k) + abs(j - l)) == d) a[to_index(i, j)][to_index(k, l)] = true;
        }
    }
  }
  vector<bool> c;
  int rank = bit_solve(a, b, c);
  cout << (rank >= 0) << endl;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  while (solve());
  return 0;
}
