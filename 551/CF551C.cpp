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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
int a[maxn], b[maxn];

bool can(ll t) {
	t--;
	int p = n-1;
	copy(b, b+n, a);
	for(int r = 0; r < m; r++) {
		ll rem = t;
		while(p >= 0 && a[p] == 0) p--;
		if(p < 0) return true;
		rem -= p;
		while(p >= 0 && rem > 0) {
			while(p >= 0) {
				int x = (int)min((ll)a[p], rem);
				a[p] -= x, rem -= x;
				if(a[p]) break;
				p--;
			}
		}
	}
	while(p >= 0) {
		if(a[p]) return false;
		p--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> a[i];
	copy(a, a+n, b);

	ll lo = 0, hi = 1e15;
	while(hi - lo > 1) {
		ll md = (lo + hi) / 2;
		if(can(md)) hi = md;
		else lo = md;
	}

	cout << hi << endl;

	return 0;
}

