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

typedef long double db;

const int CTV = 600;

int n, k;
db d[CTV], p[CTV];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	db bigsum = 0;
	db ans = 0;
	db C = 1;
//	rep(i, n) C *= (k-1) / (db)k;

	db g = 1;

	d[1] = 1;
	fer(t, 1, n+1) {
		C /= t; C *= (n-t+1);
//		C *= 1 / (db)k; C /= (k-1) / (db)k;
		db prob = pow(1 / (db)k, t) * C * pow((k-1) / (db)k, n-t);
//		db prob = C;
		db sum = 0;
		cerr << " $$ " << g << endl;
		g = 1 / (g+1) * (g+1) + (1 - 1 / (g+1)) * g;
		rof(i, CTV, 1) {
			if(i < 5) cerr << " ~~ " << i << " : " << d[i] << endl;
			sum += ((i+1) * (i+2) / 2 - 1) * d[i] / (i+1);
			p[i] = d[i] * i / (i+1) + d[i-1] / i;
		}
		bigsum += sum;
		if(k > 1) ans += bigsum * prob * k;
		else ans += bigsum * (t == n ? 1 : 0) * k;
		memcpy(d, p, sizeof d);
	}

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << ans << endl;

	return 0;
}

