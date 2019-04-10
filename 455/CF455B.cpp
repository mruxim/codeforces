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
const int maxlg = 17 + 2;

int n, k;
string s[maxn];
int d[maxn];
int r[maxlg][maxn], mx[maxlg][maxn];

pii calc(int a, int b, int len = 0) {
	int p = 0;
	while((1 << p) <= b-a) p++; p--;
	if(max(mx[p][a], mx[p][b-(1<<p)]) == len) return {-1, -1};

	if(b - a == 1)
		return {(sz(s[a]) - len) % 2, 1 - (sz(s[a]) - len) % 2};
	
	p = 0;
	while((1 << p) <= b-a-1) p++; p--;
	int md = r[p][a];
	if(d[r[p][b-1-(1<<p)]] < d[md])
		md = r[p][b-1-(1<<p)];

	pii lh = calc(a, md+1, d[md]);
	pii rh = calc(md+1, b, d[md]);
	int v = (d[md] - len) % 2;

	if(lh.X == -1) return {rh.X ^ v, rh.Y ^ v};
	if(rh.X == -1) return {lh.X ^ v, lh.Y ^ v};

	return {v ^ (lh.X | rh.X), v ^ (lh.Y | rh.Y)};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> s[i];
	rep(i, n) sort(s, s+n);

	rep(lg, maxlg) rep(i, n) {
		if(lg == 0) mx[lg][i] = sz(s[i]);
		else {
			mx[lg][i] = mx[lg-1][i];
			int j = i + (1 << (lg-1));
			if(j < n) smax(mx[lg][i], mx[lg-1][j]);
		}
	}
	rep(lg, maxlg) rep(i, n-1) {
		if(lg == 0) {
			for(int &p = d[i] = 0; p < min(sz(s[i]), sz(s[i+1])) && s[i][p] == s[i+1][p]; p++);
			r[lg][i] = i;
			continue;
		}
		r[lg][i] = r[lg-1][i];
		int j = i + (1 << (lg-1));
		if(j < n-1 && d[r[lg-1][j]] < d[r[lg][i]])
			r[lg][i] = r[lg-1][j];
	}

	pii p = calc(0, n);

	if(!p.X) cout << "Second" << endl;
	else if(p.Y) cout << "First" << endl;
	else cout << (k % 2 ? "First" : "Second") << endl;

	return 0;
}

