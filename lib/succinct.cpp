#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 2^18 = 262144

class BV {
  //
  const static int MAX_SIZE = 262144;
  const static int LG_MAX_SIZE = 18;

  //
  const static int L_BLOCK_SIZE = 1024;
  const static int L_BLOCK_COUNT = 256;

  //
  const static int S_BLOCK_SIZE = 128;
  const static int S_BLOCK_COUNT = 8;

  bitset<MAX_SIZE> data;

  vector<int> r_l, r_s;

public:

  BV(vector<bool> v) {
    r_l.resize(L_BLOCK_COUNT + 1);
    r_s.resize(S_BLOCK_COUNT * L_BLOCK_COUNT + 1);

    int n = v.size();
    assert(n <= MAX_SIZE);
    int count = 0, s_count = 0;
    int l_index = 0, s_index = 0;
    for (int i = 0; i < n; i++) {
      if (i % L_BLOCK_SIZE == 0) {
        r_l[l_index++] = count;
        s_index++;
        s_count = 0;
      } else if (i % S_BLOCK_SIZE == 0) {
        r_s[s_index++] = s_count;
      }
      data[i] = v[i];
      count += v[i];
      s_count += v[i];
    }
    for (; s_index <= S_BLOCK_COUNT * L_BLOCK_COUNT; s_index++) {
      if (s_index % S_BLOCK_COUNT == 0) {
        r_l[l_index++] = count;
        s_count = 0;
      } else {
        r_s[s_index] = s_count;
      }
    }
  }

  BV() {
    BV(vector<bool>());
  }

  bool access(int i) {
    return data[i];
  }

  // [0, r) での1の出現数
  int rank_1(int r) {
    if (r > MAX_SIZE) r = MAX_SIZE;
    int ret = r_l[r / L_BLOCK_SIZE] + r_s[r / S_BLOCK_SIZE];
    for (int i = r / S_BLOCK_SIZE * S_BLOCK_SIZE; i < r; i++) ret += data[i];
    return ret;
  }

  // [0, r)での0の出現数
  int rank_0(int r) {
    if (r > MAX_SIZE) r = MAX_SIZE;
    return r - rank_1(r);
  }

  // [0, r)でのbの出現数
  int rank(bool b, int r) {
    if (b) return rank_1(r);
    else return rank_0(r);
  }

  // [l, r)でのbの出現数
  int rank(bool b, int l, int r) {
    if (b) return rank_1(r) - rank_1(l);
    else return rank_0(r) - rank_0(l);
  }

  // rank_1(r) = s を満たすrを返す, 存在しないときは-1
  // 0のときは-1を返す
  int select_1(int s) {
    if (rank_1(MAX_SIZE) < s) return -1;
    if (s == 0) return 0;
    int l = 0, r = L_BLOCK_COUNT;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (r_l[m] >= s) {
        r = m;
      } else {
        l = m;
      }
    }
    for (int i = l * S_BLOCK_COUNT; i < r * S_BLOCK_COUNT; i++) {
      if (r_l[l] + r_s[i] >= s) {
        int c = r_l[l] + r_s[i - 1];
        for (int j = (i - 1) * S_BLOCK_SIZE; j < i * S_BLOCK_SIZE; j++) {
          if (data[j]) c++;
          if (c == s) {
            return j + 1;
          }
        }
      }
    }
    int c = r_l[l] + r_s[r * S_BLOCK_COUNT - 1];
    for (int j = (r * S_BLOCK_COUNT - 1) * S_BLOCK_SIZE; j < r * S_BLOCK_COUNT * S_BLOCK_SIZE; j++) {
      if (data[j]) c++;
      if (c == s) {
        return j + 1;
      }
    }

    // unreachable
    return 0;
  }

  int select_0(int s) {
    if (rank_0(MAX_SIZE) < s) return -1;
    if (s == 0) return 0;
    int l = 0, r = L_BLOCK_COUNT;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (m * L_BLOCK_SIZE - r_l[m] >= s) {
        r = m;
      } else {
        l = m;
      }
    }
    for (int i = l * S_BLOCK_COUNT; i < r * S_BLOCK_COUNT; i++) {
      if (i * S_BLOCK_SIZE - (r_l[l] + r_s[i]) >= s) {
        int c = (i - 1) * S_BLOCK_SIZE - (r_l[l] + r_s[i - 1]);
        for (int j = (i - 1) * S_BLOCK_SIZE; j < i * S_BLOCK_SIZE; j++) {
          if (!data[j]) c++;
          if (c == s) {
            return j + 1;
          }
        }
      }
    }
    int c = (r * S_BLOCK_COUNT - 1) * S_BLOCK_SIZE - (r_l[l] + r_s[r * S_BLOCK_COUNT - 1]);
    for (int j = (r * S_BLOCK_COUNT - 1) * S_BLOCK_SIZE; j < r * S_BLOCK_COUNT * S_BLOCK_SIZE; j++) {
      if (!data[j]) c++;
      if (c == s) {
        return j + 1;
      }
    }

    // unreachable
    return 0;
  }

  int select(bool b, int s) {
    if (b) return select_1(s);
    else return select_0(s);
  }

  void print(int n) {
    for (int i = 0; i < n; i++) cerr << data[i];
    cerr << endl;
    for (int i = 0; i < (n + L_BLOCK_SIZE - 1) / L_BLOCK_SIZE * S_BLOCK_COUNT; i++) cerr << r_s[i] << " ";
    cerr << endl;
    for (int i = 0; i <= (n + L_BLOCK_SIZE - 1) / L_BLOCK_SIZE; i++) cerr << r_l[i] << " ";
    cerr << endl;
  }
};

struct SearchRange {
  SearchRange(int l, int r, int i) : l(l), r(r), i(i) {}

  int l, r, i;
};

bool operator<(const SearchRange &l, const SearchRange &r) {
  if (l.r - l.l == r.r - r.l) {
    if (l.i == r.i) {
      return l.l > r.l;
    }
    return l.i > r.i;
  }
  return l.r - l.l < r.r - r.l;
}

template<typename T>
class WM {
  int bit_size;
  vector<pair<BV, int>> mat;
  map<T, int> s_table;
  vector<T> t;
  int n;

public:
  WM(vector<T> s, int _bit_size) {
    n = s.size();
    int part = 0;
    bit_size = 1;
    while (bit_size < _bit_size) bit_size <<= 1;
    for (int i = 0; i < bit_size; i++) {
      vector<bool> bit(n);
      vector<T> s0, s1;
      for (int j = 0; j < n; j++) {
        bool ok = (s[j] >> (bit_size - 1 - i)) & 1;
        bit[j] = ok;
        if (ok) {
          s1.push_back(s[j]);
        } else {
          s0.push_back(s[j]);
        }
      }
      mat.emplace_back(BV(bit), part);
      part = mat.back().first.rank_0(n);
      for (int j = 0; j < s0.size(); j++) s[j] = s0[j];
      for (int j = 0; j < s1.size(); j++) s[s0.size() + j] = s1[j];
    }
    for (int i = 0; i < n; i++) {
      if (s_table.find(s[i]) == s_table.end()) {
        s_table[s[i]] = i;
      } else {
        s_table[s[i]] = min(s_table[s[i]], i);
      }
    }
    t = s;
  }

  WM() {
    WM("");
  }

  // s[i]
  T access(int i) {
    T ret = 0;
    int offset = 0;
    int index = i;
    bool b = false;
    for (int i = 0; i < bit_size; i++) {
      offset = b ? mat[i].second : 0;
      int bit = mat[i].first.access(offset + index);
      b = bit;
      ret |= bit << (bit_size - 1 - i);
      index = mat[i].first.rank(bit, offset + index);
    }
    return ret;
  }

  // [0, r)のcの出現数
  int rank(T c, int r) {
    int offset = 0;
    int index = r;
    bool b = false;
    for (int i = 0; i < bit_size; i++) {
      offset = b ? mat[i].second : 0;
      b = (c >> (bit_size - 1 - i)) & 1;
      index = mat[i].first.rank(b, offset + index);
    }
    return index - s_table[c];
  }

  // rank(c, r) == sを満たす最小のs
  int select(T c, int s) {
    int index = s_table[c] + s;
    if ((index < 1 || index > n) || t[index - 1] != c) return -1;
    for (int i = bit_size - 1; i >= 0; i--) {
      bool b = (c >> (bit_size - 1 - i)) & 1;
      int offset = b ? mat[i].first.rank_0(n) : 0;
      index = mat[i].first.select(b, index - offset);
    }
    return index;
  }

  // [l, r)におけるk順位 (0位最小)
  T quantile(int l, int r, int k) {
    T ret = 0;
    for (int i = 0; i < bit_size; i++) {
      int l0 = mat[i].first.rank_0(l);
      int l1 = mat[i].first.rank_1(l);
      int c0 = mat[i].first.rank(0, l, r);
      bool b = k >= c0;
      ret |= ((int) b) << (bit_size - 1 - i);
      // cerr << l << " " << r << " " << b << endl;
      if (b) {
        k -= c0;
        l = mat[i].first.rank_0(n) + l1;
        r = n - mat[i].first.rank(1, r, n);
      } else {
        l = l0;
        r = mat[i].first.rank_0(r);
      }
    }
    return ret;
  }

  // [l, r)内の出現数順k個を取り出す
  vector<pair<T, int>> topk(int l, int r, int k) {
    priority_queue<SearchRange> q;
    q.emplace(l, r, 0);
    vector<pair<char, int>> ret;
    while (ret.size() < k && q.size()) {
      SearchRange now = q.top();
      q.pop();
      if (now.i == bit_size) {
        ret.emplace_back(t[now.l], now.r - now.l);
        continue;
      }
      int c0 = mat[now.i].first.rank(0, now.l, now.r);
      int c1 = mat[now.i].first.rank(1, now.l, now.r);
      int l0 = mat[now.i].first.rank(0, now.l);
      int l1 = mat[now.i].first.rank(0, now.l);
      int offset = mat[now.i].first.rank_0(n);
      if (c0) {
        q.emplace(l0, l0 + c0, now.i + 1);
      }
      if (c1) {
        q.emplace(offset + l1, offset + l1 + c1, now.i + 1);
      }
    }
    return ret;
  }

  // [l, r)内の要素の和
  ll sum(int l, int r) {
    auto v = topk(l, r, n);
    ll ret = 0;
    for (auto &pr : v) ret += pr.first * pr.second;
    return ret;
  }

  // [l1, r1) [l2, r2) に共通して出現する値と頻度
  vector<pair<T, pair<int, int>>> intersect(int l1, int r1, int l2, int r2) {
    vector<pair<T, pair<int, int>>> ret;
    queue<pair<SearchRange, SearchRange>> q;
    q.emplace(SearchRange(l1, r1, 0), SearchRange(l2, r2, 0));
    while (q.size()) {
      auto now = q.front();
      q.pop();
      if (now.first.i == bit_size) {
        ret.emplace_back(t[now.first.l], make_pair(now.first.r - now.first.l, now.second.r - now.second.l));
        continue;
      }
      int c00 = mat[now.first.i].first.rank(0, now.first.l, now.first.r);
      int c01 = mat[now.first.i].first.rank(1, now.first.l, now.first.r);
      int l00 = mat[now.first.i].first.rank_0(now.first.l);
      int l01 = mat[now.first.i].first.rank_1(now.first.l);
      int c10 = mat[now.second.i].first.rank(0, now.second.l, now.second.r);
      int c11 = mat[now.second.i].first.rank(1, now.second.l, now.second.r);
      int l10 = mat[now.second.i].first.rank_0(now.second.l);
      int l11 = mat[now.second.i].first.rank_1(now.second.l);
      int offset = mat[now.first.i].first.rank_0(n);

      SearchRange range00(l00, l00 + c00, now.first.i + 1);
      SearchRange range01(offset + l01, offset + l01 + c01, now.first.i + 1);
      SearchRange range10(l10, l10 + c10, now.second.i + 1);
      SearchRange range11(offset + l11, offset + l11 + c11, now.second.i + 1);

      if (range00.r - range00.l > 0 && range10.r - range10.l > 0) {
        q.emplace(range00, range10);
      }
      if (range01.r - range01.l > 0 && range11.r - range11.l > 0) {
        q.emplace(range01, range11);
      }
    }
    return ret;
  }
};

WM<char> WM_string(string s) {
  vector<char> data(s.size());
  for (int i = 0; i < s.size(); i++) data[i] = s[i];
  return WM<char>(data, 8);
}

int main() {
  string s = "abbcccddddeeeeeffffffggggggg";
  int n = s.size();
  auto wm = WM_string(s);
  /*
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = 0; i < 27; i++) cerr << wm.rank(c, i) << " ";
    cerr << endl;
  }
   */
  // for (char c = 'a'; c <= 'z'; c++) cerr << wm.select(c, 2) << endl;
  for (int i = 0; i < n; i++) {
    char c = wm.quantile(0, n, i);
    cerr << c;
  }
  cerr << endl;
  auto v = wm.topk(0, n, 2);
  for (auto &pr : v) {
    cerr << pr.first << " " << pr.second << endl;
  }
  auto w = wm.intersect(0, 2, 2, 3);
  for (auto &pr : w) {
    cerr << pr.first << " " << pr.second.first << " " << pr.second.second << endl;
  }
  return 0;
}