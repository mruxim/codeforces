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
typedef pair<double, double> pdd;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300 + 100;

pdd pa, pb;
int n;

double cross(pdd p0, pdd p1, pdd p2) {
	return (p1.X-p0.X) * (p2.Y-p0.Y) - (p1.Y-p0.Y) * (p2.X-p0.X);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> pa.X >> pa.Y;
	cin >> pb.X >> pb.Y;
	cin >> n;

	int ans = 0;
	rep(i, n) {
		double a, b, c;
		cin >> a >> b >> c;

		pdd p1, p2;
		if(abs(a) > 1e-4)
			p1 = {-c/a, 0},
			p2 = {-c/a + b, 0 - a};
		else
			p1 = {0, -c/b},
			p2 = {0 + b, -c/b - a};

		if(cross(p1, p2, pa) * cross(p1, p2, pb) < -1e-5)
			ans++;
	}

	cout << ans << endl;

	return 0;
}

