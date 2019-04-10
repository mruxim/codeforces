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

const ll inf = (ll)1e17;
const int maxd = 1000000 + 100;
const int maxn = 100000 + 100;

int n, m, k;
vector<pii> fs[maxd], ts[maxd];
int cf[maxd]; ll mf[maxd];
int ct[maxd]; ll mt[maxd];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k; k++;
	rep(i, m) {
		int d, f, t, c;
		cin >> d >> f >> t >> c; d--, f--, t--;
		if(t == -1) fs[d].pb(pii(f, c));
		else		ts[d].pb(pii(t, c));
	}

	memset(cf, -1, sizeof cf);
	int cntf = 0; ll curf = 0;
	rep(d, maxd) {
		for(pii p: fs[d])
			if(cf[p.X] == -1) cntf++, cf[p.X] = p.Y, curf += cf[p.X];
			else curf -= cf[p.X], smin(cf[p.X], p.Y), curf += cf[p.X];
		if(cntf == n) mf[d] = curf;
		else mf[d] = inf;
	}

	memset(ct, -1, sizeof ct);
	int cntt = 0; ll curt = 0;
	rof(d, maxd, 0) {
		for(pii p: ts[d])
			if(ct[p.X] == -1) cntt++, ct[p.X] = p.Y, curt += ct[p.X];
			else curt -= ct[p.X], smin(ct[p.X], p.Y), curt += ct[p.X];
		if(cntt == n) mt[d] = curt;
		else mt[d] = inf;
	}

	ll ans = inf;
	rep(d, maxd - k) smin(ans, mf[d] + mt[d + k]);

	cout << (ans == inf ? -1 : ans) << endl;

	return 0;
}

