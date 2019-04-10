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

const int maxn = 10000 + 100;

int n;
int x[maxn], y[maxn];
vector<int> v, vi;
bool mark[maxn];
vector<pii> ans;

int can(vector<int> v, int g) {
	int k = sz(v);
	int pos = 0;
	
	vector<int> s(k);
	rep(i, k) s[i] = 1<<i;

	int used = 0;

	rep(bit, 30) {
		int id = -1;
		fer(i, pos, sz(v)) if(v[i] >> bit & 1) { id = i; break; }
		
		if(id == -1 && (g >> bit & 1)) return -1;
		if(id == -1) continue;

		swap(v[pos], v[id]); swap(s[pos], s[id]);
		pos++;
		fer(i, pos, sz(v)) if(v[i] >> bit & 1) v[i] ^= v[pos-1], s[i] ^= s[pos-1];

		if(g >> bit & 1) g ^= v[pos-1], used ^= s[pos-1];
	}
	return used;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> y[i];

	rep(i, n) if(!can(v, x[i]).X) v.pb(x[i]), vi.pb(i), mark[i] = 1;

	rep(i, n) if(!mark[i]) {
		int t = can(v, y[i]);
		if(t == -1) { cout << -1 << endl; return 0; }
		rep(j, 30) if(t >> j & 1) ans.pb({i, vi[j]});
	}

	rep(i, n) if(mark[i] && y[i] != 0) {
		int t = can(v, y[i]);
		if(t == -1) { cout << -1 << endl; return 0; }

	}

	rep(i, n) if(mark[i] && y[i] == 0) ans.pb({i, i});

	return 0;
}

