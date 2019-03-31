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

class Counting {
	unsigned long long p, n;
	vector<long long> invMemo, facMemo, facInvMemo;
public:
	Counting(unsigned long long nn, unsigned long long np) {
		p = np;
		n = nn;
		invMemo.resize(n + 1);
		facMemo.resize(n + 1);
		facInvMemo.resize(n + 1);
		facMemo[0] = 1;
		facMemo[1] = 1;
		facInvMemo[0] = 1;
		facInvMemo[1] = 1;
		invMemo[0] = 0;
		invMemo[1] = 1;
		for (unsigned long long i = 2; i <= n; i++) {
			invMemo[i] = p - (p / i)*invMemo[p%i] % p;
			facMemo[i] = (facMemo[i - 1] * i) % p;
			facInvMemo[i] = (facInvMemo[i - 1] * invMemo[i]) % p;
		}
	}
	unsigned long long fac(unsigned long long k) {
		return facMemo[k];
	}
	unsigned long long facInv(unsigned long long k) {
		return facInvMemo[k];
	}
	unsigned long long choose(unsigned long long n, unsigned long long k) {
		if (!(0 <= k && k <= n))
			return 0;
		return (((facMemo[n] * facInvMemo[k]) % p)*facMemo[n - k]) % p;
	}
	unsigned long long divide(unsigned long long a, unsigned long long b) {
		return (a * invMemo[b]) % p;
	}
	unsigned long long mod(unsigned long long a) {
		a %= p;
		if (a < 0) a += p;
		return a;
	}
	unsigned long long power(unsigned long long a, unsigned long long e) {
		unsigned long long ans = 1;
		for (; e > 0; e /= 2) {
			if (e % 2 != 0)
				ans = ans * a % p;
			a = a*a%p;
		}
		return ans;
	}
};

class Node {
public:
	long long c, t;
	int now;
	Node(int nn, long long cc, long long tt) {
		c = cc;
		now = nn;
		t = tt;
	}
	bool operator<(const Node &rhs) const {
		return this->t < rhs.t;
	}
	bool operator>(const Node &rhs) const {
		return this->t > rhs.t;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> p;
	vector<vector<long long>> pcol, pcost;
	p.resize(n);
	pcol.resize(n);
	pcost.resize(n);
	for (int i = 0; i < m; i++) {
		int to, from;
		long long col, t;
		cin >> to >> from >> col >> t;
		to--; from--;
		p[to].push_back(from);
		p[from].push_back(to);
		pcol[to].push_back(col);
		pcol[from].push_back(col);
		pcost[to].push_back(t);
		pcost[from].push_back(t);
	}

	Node start(0, 1, 0);
	multiset<Node> queue;
	queue.insert(start);
	vector<map<long long, bool>> b;
	b.resize(n);
	while (queue.size() > 0) {
		Node now = *queue.begin();
		queue.erase(queue.begin());
		//cout << now.now + 1 << " " << now.t << " " << now.c << endl;
		if (now.now == n - 1) {
			cout << now.t << endl;
			break;
		}
		if (b[now.now][now.c]) {
			continue;
		}
		b[now.now][now.c] = true;
		for (int i = 0; i < p[now.now].size(); i++) {
			if (b[p[now.now][i]][pcol[now.now][i]]) {
				continue;
			}
			Node next(p[now.now][i], pcol[now.now][i], now.t + pcost[now.now][i] + abs(now.c - pcol[now.now][i]));
			queue.insert(next);
		}
	}
//	cin >> n;
	return 0;
}
