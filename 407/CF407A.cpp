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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b;
	cin >> a >> b;

	fer(ax, 1, a) {
		int ay = (int)sqrt(a*a - ax*ax + 0.5);
		if(ax*ax + ay*ay != a*a) continue;
		int bx = 1, by = 1;
		for(; 1; bx++) {
			while(bx*ax > ay*by) by++;
			if(bx*ax != ay*by || ax == bx) continue;
			if(bx*bx + by*by > b*b) break;
			if(bx*bx + by*by == b*b) {
				cout << "YES" << endl;
				cout << 0 << ' ' << 0 << endl;
				cout << ax << ' ' << ay << endl;
				cout << bx << ' ' << -by << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	{ return 0; }
}

