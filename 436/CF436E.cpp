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

const int maxn = 300000 + 100;
const int ctv = 300;

int n, w;
ll dp[maxn/ctv+10][2*ctv+10];

void calc(int l, int r, ll out[2*ctv+10]) {
	memset(out, 50, sizeof out);
	out[0] = 0;
	fer(i, l, r) {
		rof(j, 2*(i-l+1)+1, 2) {
			if(out[j] > out[j-2] + b[i]) out[j] = out[j-2] + b[i];
			if(out[j] > out[j-1] + a[i]) out[j] = out[j-1] + a[i];
		}
		if(out[1] > a[i]) out[1] = a[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> w;
	rep(i, n) cin >> a[i] >> b[i];

	int t = 0;
	for(int pos = 0; pos < n; pos += ctv, t++)
		calc(pos, min(pos+ctv, n), dp[t]);

	{ return 0; }
}

