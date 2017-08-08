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

#define P 1000000007

using namespace std;

template<typename T> class RMQ {
public:
        T operator()(T left, T right) { return min(left, right); }
        T init() { return 1 << 20; }
};

template<typename T> class Sum {
public:
        T operator()(T left, T right) { return left + right; }
        T init() { return 0; }
};

struct RL {
        int ind, i, j, low, high;
};
vector<int> do_split(int i, int j, int low, int high){
        vector<int> result;
        queue<RL> q; // bfs
        q.push({0, i, j, low, high});
        while (!q.empty()) {
                RL t = q.front(); q.pop();
                // cout << t.ind << ":" << t.i << " " << t.j << " " << t.low << " " << t.high << endl;
                if (t.i == t.low && t.j == t.high) { // perfect match
                        result.push_back(t.ind);
                } else if (t.i < t.j && // non-zero query range
                           t.low+1 != t.high) { // can split more
                        int mid = (t.low + t.high) / 2;
                        q.push({t.ind*2+1, t.i, min(t.j, mid), t.low, mid});
                        q.push({t.ind*2+2, max(t.i, mid), t.j, mid, t.high});
                }
        }
        return result;
}

template<typename T, typename Op> class SegTree {
public:
    int n;
    vector<T> data;
    T t0;
    SegTree(){};
    SegTree(int n_) {
            int n = n_;
            int m = 1;
            while (m < n) { m = m << 1; }
            data = vector<T>(m*2);
            int i;
            for (i=0; i<data.size(); i++) { data[i] = Op().init(); }
    }
    void update(int i, T x) {
            int k = (data.size() / 2) + i - 1;
            data[k] = x;
            while (k>0) {
                    k = (k-1) / 2;
                    T t = Op()(data[k*2+1], data[k*2+2]);
                    data[k] = t;
            }
    }
    // [i, j)
    vector<int> split(int i, int j){
            return do_split(i, j, 0, data.size()/2);
    }
    T operator[](int i){
            return data[i];
    }
    T query(int i, int j){
            T x = Op().init();
            for(int e: split(i, j)){
                    x = Op()(x, data[e]);
            }
            return x;
    }

    void p() {
            int i;
            for(i=0; i<data.size(); i++){
                    cout << data[i] << " ";
            }
            cout<<endl;
    }
};

class A {
public:
  int l, r;
  A(int ll, int rr) {
    l = ll;
    r = rr;
  }
};

SegTree<A, RMQ> s;

bool operator>(const A &lhs, const A &rhs) const {
  return s(lhs.l, lhs.r).first > s(rhs.l, rhs.r).first;
}

bool operator<(const A &lhs, const A &rhs) const {
  return s(lhs.l, lhs.r).first > s(rhs.l, rhs.r).first;
}

int main() {
  int n;
  cin >> n;
  vector<int> p;
  p.resize(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) p[i]--;
  multiset<A> pri;
  A a(0, n - 1);
  return 0;
}
