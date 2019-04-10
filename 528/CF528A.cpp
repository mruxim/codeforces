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

int w, h, n;
set<int> Ws, hs;
multiset<int> wp, hp;

void update(set<int> &s, multiset<int> &p, int v) {
	auto nx = s.lower_bound(v);
	auto pr = nx; pr--;
	int dis = *nx - *pr;
	p.erase(p.find(dis));
	s.insert(v);
	p.insert(v - *pr);
	p.insert(*nx - v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> w >> h >> n;

	Ws.insert(0); Ws.insert(w);
	wp.insert(w);
	hs.insert(0); hs.insert(h);
	hp.insert(h);

	rep(z, n) {
		char tp; int v;
		cin >> tp >> v;
		if(tp == 'H')
			update(hs, hp, v);
		else
			update(Ws, wp, v);

		cout << (*--wp.end()) * (ll)(*--hp.end()) << endl;
	}

	return 0;
}

