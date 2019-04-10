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

const int len = 30000+100;

int n, d;
int p[len];
int s[len];
unordered_map<int, int> dpm[len];

int go(int pos, int jump) {
	if(pos > len-50) return 0;
	if(jump <= 2) return s[pos];
	if(dpm[pos].find(jump) != dpm[pos].end()) return dpm[pos][jump];
	
	int res = 0;
	smax(res, go(pos + jump, jump));
	smax(res, go(pos + jump+1, jump+1));
	if(jump > 1) smax(res, go(pos + jump-1, jump-1));

	res += p[pos];
	dpm[pos][jump] = res;
	return res;
}

int dp[len][1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> d;
	rep(i, n) {
		int x;
		cin >> x;
		p[x]++;
	}

	rof(i, len-1, 0) s[i] = p[i] + s[i+1];

	if(d > 700) cout << go(d, d) << endl;
	else {
		int ans = 0;
		memset(dp, -50, sizeof dp);
		dp[d][d] = 0;
		fer(pos, d, len-50) fer(jump, 1, 1000) {
			dp[pos][jump] += p[pos];
			smax(ans, dp[pos][jump]);
			if(pos + jump < len)
				smax(dp[pos+jump][jump], dp[pos][jump]);
			if(pos + jump + 1 < len && jump + 1 < 1000)
				smax(dp[pos+jump+1][jump+1], dp[pos][jump]);
			if(pos + jump - 1 < len && jump - 1 >= 1)
				smax(dp[pos+jump-1][jump-1], dp[pos][jump]);
		}

		cout << ans << endl;
	}

	return 0;
}

