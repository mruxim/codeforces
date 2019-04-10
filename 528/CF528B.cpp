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

const int maxn = 200000 + 100;

int n;
pii p[maxn];
int a[maxn], b[maxn];
int fen[maxn];

int get(int pos) {
	int r = 0;
	for(; pos; pos -= pos & -pos)
		smax(r, fen[pos]);
	return r;
}

void add(int pos, int val) {
	for(pos++; pos < maxn; pos += pos & -pos)
		smax(fen[pos], val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> p[i].X >> p[i].Y;

	sort(p, p+n);
	iota(a, a+n, 0);
	sort(a, a+n, [](int i, int j){ return p[i].X+p[i].Y < p[j].X+p[j].Y; });
	rep(i, n) b[a[i]] = i;

	int ans = 0;

	rep(i, n) {
		int lo = -1, hi = n;
		while(hi-lo > 1) {
			int md = (lo + hi) / 2;
			if(p[a[md]].X+p[a[md]].Y <= p[i].X-p[i].Y)
				lo = md;
			else
				hi = md;
		}
		int mx = get(hi);
		smax(ans, mx+1);
		add(b[i], mx+1);
	}

	cout << ans << endl;

	return 0;
}

