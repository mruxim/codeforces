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

const int maxn = 100000 + 100;

int n;
bool ip[maxn];
vector<int> dv[maxn];
vector<int> ml[maxn];
bool used[maxn];
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	fer(i, 2, n+1) if(sz(dv[i]) == 0) {
		ip[i] = true;
		for(int j = i; j <= n; j += i)
			dv[j].pb(i), ml[i].pb(j);
	}

	rof(i, n+1, 1) if(ip[i]) {
		for(int x: ml[i]) dv[x].erase(lower_bound(all(dv[x]), i), dv[x].end());
		int pt = 0;
		rep(k, sz(ml[i])) if(!used[ml[i][k]]) ml[i][pt++] = ml[i][k];
		ml[i].resize(pt);
		sort(all(ml[i]), [](int x, int y) { return sz(dv[x]) < sz(dv[y]); });
		for(int k = 0; k+1 < sz(ml[i]); k += 2) {
			int x = ml[i][k], y = ml[i][k+1];
			used[x] = used[y] = 1;
			ans.pb({x, y});
		}
	}

	cout << sz(ans) << endl;
	for(pii p: ans) cout << p.X << ' ' << p.Y << endl;

	{ return 0; }
}

