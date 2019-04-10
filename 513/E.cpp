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

const int maxn = 400 + 10;
const int maxk = 50 + 5;

int n;
pii dp[2][2][maxk];
pii odp[2][2][maxk];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	rep(i, n) cin >> a[i];

	rep(z, n) {
		int x = a[i];
		memcpy(odp, dp, sizeof dp);
		mul = turn * (2 * dir - 1);
		smax(dp[k][dir][turn], odp[k][dir][turn] + mul * x);
	}

	return 0;
}

