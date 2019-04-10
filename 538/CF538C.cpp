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

int n, m;
int pd, ph;
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	cin >> pd >> ph;

	smax(ans, ph + pd - 1);

	rep(i, m-1) {
		int d, h;
		cin >> d >> h;

		if(d - pd < abs(ph - h)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

		smax(ans, max(ph, h) + ((d - pd - abs(ph - h)) / 2));

		pd = d, ph = h;
	}

	smax(ans, n - pd + ph);

	cout << ans << endl;

	return 0;
}

