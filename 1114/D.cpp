// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;

int n;
short c[maxn];
short dp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> c[i];

	memset(dp, 50, sizeof dp);
	rep(i, n) dp[i][i+1] = 0;
	fer(l, 2, n+1)
		rep(i, n-l+1) {
			int j = i + l;
			if(c[i] == c[i+1]) dp[i][j] = dp[i+1][j];
			else if(c[j-1] == c[j-2]) dp[i][j] = dp[i][j-1];
			else {
				smin(dp[i][j], dp[i+1][j] + 1);
				smin(dp[i][j], dp[i][j-1] + 1);
				if(c[i] == c[j-1]) smin(dp[i][j], dp[i+1][j-1] + 1);
			}
		}

	cout << dp[0][n] << endl;

	return 0;
}

