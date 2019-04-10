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

double len(vector<pii> v) {
	double res = 0;
	rep(i, 3) res += hypot(v[i].X - v[i+1].X, v[i].Y - v[i+1].Y);
	return res;
}

vector<pii> solve(int n, int m) {
	vector<pii> v1({{1, 0}, {n, m}, {0, 0}, {n-1, m}});
	vector<pii> v2({{0, 0}, {n, m}, {n, 0}, {0, m}});
	if(len(v1) > len(v2)) return v1;
	return v2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(n == 0) {
		cout << "0 1" << endl;
		cout << "0 " << m << endl;
		cout << "0 0" << endl;
		cout << "0 " << m-1 << endl;
	} else if(m == 0) {
		cout << "1 0" << endl;
		cout << n << " 0" << endl;
		cout << "0 0" << endl;
		cout << n-1 << " 0" << endl;
	} else {
		vector<pii> v;
		if(n > m) {
			v = solve(m, n);
			rep(i, 4) swap(v[i].X, v[i].Y);
		}
		else v = solve(n, m);
		rep(i, 4) cout << v[i].X << ' ' << v[i].Y << endl;
	}

	{ return 0; }
}

