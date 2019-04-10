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

const ll base = 1003;

void func(string s, map<ll, int> h, int len) {
	if(len > sz(s)) return;

	ll hash = 0, mul = 1;
	rep(i, len) hash = hash * base + s[i], mul = mul * base;
	rep(i, sz(s) - len + 1) {
		h[hash]++;
		hash *= base;
		hash -= s[i] * mul;
		if(i + len < sz(s)) hash += s[i + len];
	}
}

string s, t;
map<ll, int> sh, th;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s >> t;

	int lo = 0, hi = 6000;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		
		sh.clear(), th.clear();

		func(s, sh, md);
		func(t, th, md);

		bool ok = false;

		for(auto p: sh) {
			int x = p.second;
			int y = th[p.first];
			if(x == 1 && y == 1) ok = true;
		}

		if(ok) hi = md;
		else lo = md;
	}

	if(lo == 0) cout << -1 << endl;
	else cout << lo << endl;

	{ return 0; }
}

