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

int n, m;
pii p[maxn];
int v[maxn];
int rev[maxn];

main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> p[i].X, p[i].Y = i;
	sort(p, p+n);
	rep(i, n) v[i] = p[i].X;
	rep(i, n) rev[p[i].Y] = i;

	while(m--) {
		int id, len; cin >> id >> len; id--;
		id = rev[id];

		while(1) {
			int a = upper_bound(v, v+n, v[id] + len) - v - 1;
			int b = lower_bound(v, v+n, v[a] - (len - (v[a] - v[id]))) - v;
			if(a == id && b == id) { cout << p[id].Y + 1 << endl; break; }
			if(a == id) len -= v[id] - v[b], id = b;
			else if(b == id) len %= 2 * (v[a] - v[id]);
			else {
				len -= (v[a] - v[id]) + (v[a] - v[b]);
				id = b;
			}
		}
	}


	return 0;
}

