// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int t, q;
int qx[maxn], qy[maxn];
char qc[maxn];
int n;
unordered_set<int> used[maxn];

struct seg {
	int v[maxn];
	int p[4*maxn];

	void add(int x, int xl, int xr, int ql, int qr, int qv) {
		if(qr <= xl || xr <= ql) return;
		if(ql <= xl && xr <= qr) {
			smax(p[x], qv);
			return;
		}
		int xm = (xl + xr) / 2;
		add(2*x+1, xl, xm, ql, qr, qv);
		add(2*x+2, xm, xr, ql, qr, qv);
	}

	int get(int x, int xl, int xr, int qp) {
		if(qp < xl || xr <= qp) return -1;
		if(xr - xl == 1) return p[x];
		int xm = (xl + xr) / 2;
		return max(p[x], max(get(2*x+1, xl, xm, qp), get(2*x+2, xm, xr, qp)));
	}
} segx, segy;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t >> q;
	rep(i, q) {
		cin >> qx[i] >> qy[i] >> qc[i];
		segx.v[n] = qx[i], segy.v[n] = qy[i], n++;
	}

	segx.v[n] = 0, segy.v[n] = 0, n++;
	segx.v[n] = 1e9+5, segy.v[n] = 1e9+5, n++;

	sort(segx.v, segx.v+n);
	unique(segx.v, segx.v+n);
	sort(segy.v, segy.v+n);
	n = unique(segy.v, segy.v+n) - segy.v;

	rep(i, q) {
		int x = lower_bound(segx.v, segx.v+n, qx[i]) - segx.v;
		int y = lower_bound(segy.v, segy.v+n, qy[i]) - segy.v;
		if(used[x].find(y) != used[x].end())
			cout << 0 << endl;
		else if(qc[i] == 'U') {
			int t = segx.get(0, 0, n, x);
			segy.add(0, 0, n, t+1, y+1, x);
			cout << segy.v[y] - segy.v[t] << endl;
		} else {
			int t = segy.get(0, 0, n, y);
			segx.add(0, 0, n, t+1, x+1, y);
			cout << segx.v[x] - segx.v[t] << endl;
		}
		used[x].insert(y);
	}

	return 0;
}

