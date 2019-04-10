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

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	ll mx = n - m + 1;
	mx = mx * (mx-1) / 2;

	ll s = n / m;
	int b = n % m, a = m - b;
	ll mn = a * s * (s-1) / 2 + b * s * (s+1) / 2;

	cout << mn << ' ' << mx << endl;

	return 0;
}

