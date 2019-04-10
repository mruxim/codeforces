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

const int maxn = 1000000 + 100;

int n;
int p[maxn];
int d[maxn], m1[maxn], m2[maxn];

inline void update(int v, int u) {
	if(m1[v] == u) return;
	if(m2[v] != u && (m2[v] == 0 || d[u] > d[m2[v]])) m2[v] = u;
	if(m1[v] == 0 || d[u] > d[m1[v]]) m2[v] = m1[v], m1[v] = u;
}

inline int newd(int v) {
	int res = 1;
	if(m1[v]) smax(res, d[m1[v]]);
	if(m2[v]) smax(res, d[m2[v]] + 1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int v = i+1;
		cin >> p[v], p[v]--;

		d[v] = newd(v);

		while(v != 0) {
			update(p[v], v);
			if(d[p[v]] == newd(p[v])) break;
			v = p[v];
			d[v] = newd(v);
		}

		cout << d[m1[0]] << ' ';
	}
	cout << endl;

	{ return 0; }
}

