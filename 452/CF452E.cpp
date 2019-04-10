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

const int mod = 1000000007;

const int maxn = 300000 + 100;
const int maxlg = 19 + 1;

string str[3];
string s;
int n;
int p[maxlg][maxn];
pair<ll, int> tmp[maxn];
int rnk[maxn], rev[maxn];
int cnt[3][maxn];
int ne[maxn], pr[maxn];
int mn[maxn];
int w[maxn];
vector<pii> v;
int ps[maxn];

void suffarr() {
	rep(i, n) p[0][i] = (int)s[i];
	int cl = 1;
	fer(g, 1, maxlg) {
		rep(i, n) tmp[i] = {p[g-1][i] * (ll)maxn + (i+cl<n ? p[g-1][i+cl] : -1), i};
		sort(tmp, tmp+n);
		rep(i, n) p[g][tmp[i].Y] = ((i && tmp[i].X == tmp[i-1].X) ? p[g][tmp[i-1].Y] : i);
		cl += cl;
	}
	rep(i, n) rnk[i] = p[maxlg-1][i], rev[rnk[i]] = i;
}

int getid(int x) {
	x = rev[x];
	if(x < sz(str[0])) return 0;
	if(x == sz(str[0])) return -1;
	if(x < sz(str[0]) + 1 + sz(str[1])) return 1;
	if(x == sz(str[0]) + 1 + sz(str[1])) return -1;
	return 2;
}

int lcs(int x, int y) {
	int res = 0;
	rof(i, maxlg, 0)
		if(p[i][x] == p[i][y])
			res += 1 << i, x += 1 << i, y += 1 << i;
	return res;
}

void add(int st, int thr) {
	int cur = mn[st];
	int ed = ne[st];
	int hm = (cnt[0][ed] - cnt[0][st]) * (ll)(cnt[1][ed] - cnt[1][st]) % mod * (ll)(cnt[2][ed] - cnt[2][st]) % mod;
	ps[thr] += hm; if(ps[thr] >= mod) ps[thr] -= mod;
	ps[cur] -= hm; if(ps[cur] <= 0) ps[cur] += mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	rep(i, 3) cin >> str[i];
	s = str[0] + '0' + str[1] + '1' + str[2];
	n = sz(s);

	suffarr();

	rep(i, n) ne[i] = i+1, pr[i+1] = i;
	fer(i, 1, n) {
		w[i] = lcs(rev[i], rev[i-1]);
		v.pb({w[i], i});
	}
	sort(all(v));

	rep(i, n) {
		rep(j, 3) cnt[j][i+1] += cnt[j][i];
		int id = getid(i);
		if(id != -1) cnt[id][i+1]++;
	}

	rep(i, n+1) mn[i] = maxn-1; // dont care!

	rof(z, n-1, 0) {
		int pos = v[z].Y;
		add(pr[pos], v[z].X);
		add(pos, v[z].X);
		ne[pr[pos]] = ne[pos];
		pr[ne[pos]] = pr[pos];
		mn[pr[pos]] = v[z].X;
	}

	int ans = 0;
	int lim = min(sz(str[0]), min(sz(str[1]), sz(str[2])));
	rep(i, lim) {
		ans += ps[i];
		if(ans >= mod) ans -= mod;
		cout << ans << ' ';
	}
	cout << endl;

	{ return 0; }
}

