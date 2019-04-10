// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 + 100;

struct fen {
	vector<int> f;
	void init(int n) { f.resize(n + 1); }
	void add(int pos, int val) {
		for(pos++; pos < sz(f); pos += pos & -pos) f[pos] += val;
	}
	int get(int pos) {
		int res = 0;
		for( ; pos; pos -= pos & -pos) res += f[pos];
		return res;
	}
	int getrange(int p1, int p2) {
		return get(p2) - get(p1);
	}
} v[maxn], h[maxn];


int solve(int n, int m, fen v[maxn], int x, int y) {
	int miny = 0, maxy = m;
	int res = 0;
	rof(i, x+1, 0) {
		while(miny < y && v[i].getrange(miny, y+1) > 0) miny++;
		while(v[i].getrange(y, maxy) > 0) maxy--;
		smax(res, (x - i + 1) * (maxy - miny));
	}
	miny = 0, maxy = m;
	fer(i, x, n) {
		while(miny < y && v[i].getrange(miny, y+1) > 0) miny++;
		while(v[i].getrange(y, maxy) > 0) maxy--;
		smax(res, (i - x + 1) * (maxy - miny));
	}
	return res;
}

int n, m, q;
int a[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> q;

	rep(i, n) v[i].init(m);
	rep(i, m) h[i].init(n);

	rep(i, n) rep (j, m) {
		cin >> a[i][j];
		a[i][j] ^= 1;
		if(a[i][j] == 1)
			v[i].add(j, 1),
			h[j].add(i, 1);
	}

	rep(z, q) {
		int op, x, y;
		cin >> op >> x >> y;
		x--, y--;
		if(op == 1) {
			a[x][y] ^= 1;
			v[x].add(y, 2 * a[x][y] - 1);
			h[y].add(x, 2 * a[x][y] - 1);
		} else 
			cout << max(solve(n, m, v, x, y), solve(m, n, h, y, x)) << endl;
	}

	{ return 0; }
}

