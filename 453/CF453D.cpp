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

const int maxm = 20;
const int maxlg = 63;

int m;
ll t;
int p;
int dp[maxm+1][1<<maxm];
int b[maxlg+5][maxm+1];
int comb[maxm+1][maxm+1];
int ansb[maxm+1], tmpb[maxm+1];

void multiply(int A[maxm+1], int B[maxm+1], int C[maxm+1]) {
	memset(C, 0, sizeof ansb);
	rep(i, m+1) rep(j, m+1) rep(k, m+1) if((i+j+k)%2==0) {
		int overlap = (i + j - k) / 2;
		if(overlap < 0 || overlap > min(i, j) || overlap > m - k) continue;
		C[k] = (C[k] + A[i] * (ll)B[j] % p * (ll)comb[m-k][overlap] % p * (ll)comb[k][i - overlap]) % p;
	}
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> m >> t >> p;

	rep(i, maxm+1) {
		comb[i][0] = comb[i][i] = 1;
		fer(j, 1, i) comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % p;
	}

//	rep(i, 1<<m) cin >> dp[0][i], dp[0][i] %= p;
	rep(i, 1<<m) scanf("%d", &dp[0][i]), dp[0][i] %= p;
//	rep(i, m+1) cin >> b[0][i], b[0][i] %= p;
	rep(i, m+1) scanf("%d", &b[0][i]), b[0][i] %= p;

	rep(bit, m) rof(cnt, bit+2, 1) rep(i, 1<<m) {
		dp[cnt][i] += dp[cnt-1][i ^ (1 << bit)];
		if(dp[cnt][i] >= p) dp[cnt][i] -= p;
	}

	fer(lg, 1, maxlg) multiply(b[lg-1], b[lg-1], b[lg]);

	ansb[0] = 1;
	rep(lg, maxlg) if(t >> lg & 1) {
		memcpy(tmpb, ansb, sizeof ansb);
		multiply(tmpb, b[lg], ansb);
	}

	rep(i, 1<<m) {
		int res = 0;
		rep(cnt, m+1) res = (res + ansb[cnt] * (ll)dp[cnt][i]) % p;
//		cout << res << endl;
		printf("%d\n", res);
	}

	return 0;
}
