// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;

int n, m;
vector<pii> e;
int udeg[maxn], vdeg[maxn], ucnt[maxn], vcnt[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		udeg[u]++, vdeg[v]++;
		e.pb(pii(u, v));
	}

	rep(i, m) {
		int u = e[i].X, v = e[i].Y;
		if(udeg[u] % 2) vcnt[v]++;
		if(vdeg[v] % 2) ucnt[u]++;
	}

	int tot = 0;
	rep(i, n) tot += udeg[i] % 2 + vdeg[i] % 2;

	rep(i, m) {
		int u = e[i].X, v = e[i].Y;
		if(	(ucnt[u] == udeg[u] || (ucnt[u] == udeg[u]-1 && vdeg[v] % 2 == 0)) &&
			(vcnt[v] == vdeg[v] || (vcnt[v] == vdeg[v]-1 && udeg[u] % 2 == 0)) && tot == ucnt[u] + vcnt[v])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

