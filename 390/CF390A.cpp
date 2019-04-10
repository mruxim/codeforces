
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

int n;
set<int> sx, sy;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) {
		int x, y; cin >> x >> y;
		sx.insert (x);
		sy.insert (y);
	}
	cout << min (sz(sx), sz(sy)) << endl;

	{ return 0; }
}

