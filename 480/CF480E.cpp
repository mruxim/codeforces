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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;

int n, m, k;
int f[maxn][maxn];
vector<pii> v;
vector<int> ans;

inline void add(int xx, int yy, int val) {
	for(int x = xx+1; x <= n; x += x & -x)
		for(int y = yy+1; y <= m; y += y & -y)
			f[x][y] += val;
}

inline int get(int xx, int yy) {
	int r = 0;
	for(int x = xx; x; x -= x & -x)
		for(int y = yy; y; y -= y & -y)
			r += f[x][y];
	return r;
}

inline bool check(int x, int y, int len) {
	if(x < 0 || y < 0 || x+len > n || y+len > m) return false;
	return get(x+len, y+len) - get(x, y+len) - get(x+len, y) + get(x, y) == 0;
}

int expand(int x, int y, int clen) {
	for(bool ct = true; !(ct = !ct); ) {
		if(check(x-1, y, clen+1)) x--, clen++, ct = 1;
		if(check(x, y-1, clen+1)) y--, clen++, ct = 1;
		if(check(x-1, y-1, clen+1)) x--, y--, clen++, ct = 1;
		if(check(x, y, clen+1)) clen++, ct = 1;
	}
	return clen;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	rep(i, n) {
		string str; cin >> str;
		rep(j, m) if(str[j] == 'X') add(i, j, 1);
	}

	v.resize(k);
	rep(i, k) cin >> v[i].X >> v[i].Y, v[i].X--, v[i].Y--, add(v[i].X, v[i].Y, 1);

	int len = 0;

	rep(i, n) rep(j, m) while(check(i, j, len+1)) len++;

	rof(z, k, 0) {
		ans.pb(len);
		if(z == 0) break;
		add(v[z].X, v[z].Y, -1);
		for(int dx: {-1, 0}) for(int dy: {-1, 0}) {
			int x = v[z].X, y = v[z].Y, clen = 1;
			while(check(x+dx, y+dy, clen+1)) x += dx, y += dy, clen++;
			smax(len, expand(x, y, clen));
		}
	}

	reverse(all(ans));
	rep(i, k) cout << ans[i] << endl;

	return 0;
}

