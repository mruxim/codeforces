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

const int lim = 100000;

ll x, k;
vector<ll> dv;
vector<ll> ans;
vector<int> p[99999];
int st[50][lim], ed[50][lim];

void go(int id, int k) {
	if(sz(ans) >= lim) return;
	if(id == 0 || k == 0) { ans.pb(dv[id]); return; }
/*
	if(id < 50) {
		if(st[id][k] != -1) {
			fer(z, st[id][k], ed[id][k]) {
				if(sz(ans) >= lim) return;
				ans.pb(ans[z]);
			}
			return;
		} else st[id][k] = sz(ans);
	}
*/	

	for(int t: p[id]) {
		if(sz(ans) >= lim) return;
		go(t, k-1);
	}

//	if(id < 50) ed[id][k] = sz(ans);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> x >> k;

	if(x == 1) { cout << 1 << endl; return 0; }

	if(k == 0) {
		cout << x << endl;
		return 0;
	}
	
	if(k >= lim) {
		rep(i, lim) cout << 1 << ' '; cout << endl;
		return 0;
	}
	
	for(ll d = 1; d*d <= x; d++) if(x % d == 0) {
		dv.pb(d);
		if(d*d != x) dv.pb(x/d);
	}
	sort(all(dv));
	rep(i, sz(dv)) rep(j, i+1)
		if(dv[i] % dv[j] == 0)
			p[i].pb(j);

	ans.reserve(lim);
	memset(st, -1, sizeof st);
	go(sz(dv)-1, k);

	rep(i, sz(ans)) cout << ans[i] << ' '; cout << endl;

	{ return 0; }
}

