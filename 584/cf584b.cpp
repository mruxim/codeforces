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

const int mod = 1000000000+7;

int pm(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = r * (ll)a % mod;
		a = a * (ll)a % mod;
		b >>= 1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int ans = (pm(3, 3*n) - pm(7, n) + mod) % mod;
	cout << ans << endl;

	return 0;
}

