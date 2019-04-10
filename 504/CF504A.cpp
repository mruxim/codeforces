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

const int maxn = 1<<17;

int n;
int d[maxn], s[maxn];
queue<int> q;
vector<pii> edges;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> d[i] >> s[i];

	rep(i, n) if(d[i] == 1) q.push(i);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(d[u] != 1) continue;

		int v = s[u];
		edges.pb({u, v});

		s[v] ^= u;
		if(--d[v] == 1) q.push(v);
	}

	cout << sz(edges) << endl;
	for(pii p: edges) cout << p.X << ' ' << p.Y << endl;

	return 0;
}

