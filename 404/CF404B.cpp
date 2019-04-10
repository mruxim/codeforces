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

double a, d;
int n;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> a >> d;
	cin >> n;

	cout.setf(ios::fixed);
	cout.precision(8);

	fer(i, 1, n+1) {
		double len = fmod(i * d, 4 * a);
		if(len <= a) cout << len << ' ' << 0 << endl;
		else if(len <= 2*a) cout << a << ' ' << len-a << endl;
		else if(len <= 3*a) cout << 3*a-len << ' ' << a << endl;
		else cout << 0 << ' ' << 4*a-len << endl;
	}

	{ return 0; }
}

