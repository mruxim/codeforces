// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;
const int maxq = 200000 + 100;

int n, q;
int p[maxn];
vector<pii> L[maxn], R[maxn];
int fen[maxn];
ll ans[maxq];

void add(int x) {
	for(x++; x < maxn; x += x & -x) fen[x]++;
}

int get(int x) {
	int res = 0;
	for(; x; x -= x & -x) res += fen[x];
	return res;
}


inline ll bino(int x) { return x * (ll)(x - 1) / 2; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	rep(i, n) cin >> p[i], p[i]--;

	rep(i, q) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		ans[i] = bino(n) - bino(x1) - bino(y1) - bino(n - x2) - bino(n - y2);
		L[x1].pb(pii(i, y1)); L[x1].pb(pii(i, y2 - n));
		R[x2].pb(pii(i, y1)); R[x2].pb(pii(i, y2 - n));
	}

	rep(i, n) {
		for(pii p: L[i]) {
			if(p.Y > 0) ans[p.X] += bino(get(p.Y));
			if(p.Y < 0) ans[p.X] += bino(i - get(p.Y + n));
		}
		add(p[i]);
	}

	memset(fen, 0, sizeof fen);

	rof(i, n, 0) {
		for(pii p: R[i + 1]) {
			if(p.Y > 0) ans[p.X] += bino(get(p.Y));
			if(p.Y < 0) ans[p.X] += bino((n - i - 1) - get(p.Y + n));
		}
		add(p[i]);
	}

	rep(i, q) cout << ans[i] << endl;
	
	return 0;
}

