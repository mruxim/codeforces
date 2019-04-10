
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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 4*1000000 + 100;

int n, m, w;
ll fm[2][maxn], fa[2][maxn];

void addX (ll *f, int pos, ll val) {
	for (pos++; pos < maxn; pos += pos & -pos) f[pos] += val;
}

ll getX (ll *f, int pos) {
	ll ret = 0;
	for (; pos; pos -= pos & -pos) ret += f[pos];
	return ret;
}

void add (int id, int l, int r, ll val) {
	addX (fa[id], l, -val*l);
	addX (fm[id], l, val);
	addX (fa[id], r, val*r);
	addX (fm[id], r, -val);
}

ll get (int id, int pos) {
	return getX (fa[id], pos) + getX (fm[id], pos) * pos;
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> w;
	while (w--) {
		int tp, x1, y1, x2, y2;
		cin >> tp >> x1 >> y1 >> x2 >> y2; x1--, y1--;
		if (tp == 0) {
			int val; cin >> val;
			add (0, x1, x2, (y2-y1)*val);
			add (1, y1, y2, (x2-x1)*val);
		} else {
			ll ans = get (0, n) - get (0, x2) + get (0, x1);
			ans -= get (1, y2) - get (1, y1);
			cout << -ans << endl;
		}
	}

	{ return 0; }
}

