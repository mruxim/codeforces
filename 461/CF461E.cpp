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

const int maxn = 100000 + 100;
const int maxlg = 18 + 1;

ll k;
int n;
string s;
int p[maxlg][maxn];
pair<pii, int> t[maxn];
int r[maxn];
int fa[maxn], fd[maxn];

void suff_arr() {
	rep(i, n) p[0][i] = s[i];
	fer(c, 1, maxlg) {
		rep(i, n) t[i] = {{p[c-1][i], i+(1<<(c-1)) < n ? p[c-1][i+(1<<(c-1))] : -1}, i};
		sort(t, t+n);
		rep(i, n) p[c][t[i].Y] = (i && t[i].X == t[i-1].X) ? p[c][t[i-1].Y] : i;
	}
	rep(i, n) r[p[maxlg-1][i]] = i;
}

int lcp(int i, int j) {
	int res = 0;
	rof(c, maxlg, 0)
		if(p[c][i] == p[c][j])
			i += 1 << c, j += 1 << c, res += 1 << c;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> k;
	cin >> s; n = sz(s);

	fa[n] = n;
	rof(i, n, 0) if(s[i] != 'A') fa[i] = i; else fa[i] = fa[i+1];
	fd[n] = n;
	rof(i, n, 0) if(s[i] != 'D') fd[i] = i; else fd[i] = fd[i+1];

	suff_arr();
	s += "#";

	int res = n;
	rep(i, n-1) {
		int len = lcp(r[i], r[i+1]);
		int z;
		
		z = fa[r[i+1] + len];
		if(z != n) smin(res, z - r[i+1] + 1);

		z = fd[r[i] + len];
		if(z != n) smin(res, z - r[i] + 1);


		if(len + max(r[i], r[i+1]) < n && s[r[i+1] + len] - s[r[i] + len] > 1) smin(res, len);
	}

	if(fa[r[0]] != n) smin(res, fa[r[0]] - r[0] + 1);
	if(fd[r[n-1]] != n) smin(res, fd[r[n-1]] - r[n-1] + 1);

	cerr << " ~~ " << res << endl;
	cout << (k + res - 1) / res << endl;

	return 0;
}

