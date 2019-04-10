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

const int mod = 1000000000+7;

int r, g;
int s, h;
int dp[200000+100];
int odp[200000+100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> r >> g;
	s = r + g;
	
	for(h = 1; h*(h+1)/2 <= s; h++); h--;

	dp[0] = 1;
	fer(i, 1, h+1) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		fer(p, 0, r+1)
			dp[p] = odp[p] + (p >= i ? odp[p-i] : 0),
			dp[p] = (dp[p] >= mod ? dp[p] - mod : dp[p]);
	}

	int ans = 0;
	fer(p, 0, r+1) if(h*(h+1)/2 - p <= g)
		ans = (ans + dp[p]) % mod;
	
	cout << ans << endl;

	return 0;
}

