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

int n;
int c[5][5];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		string card; cin >> card;
		if(card[0] == 'B') card[0] = 'A';
		if(card[0] == 'G') card[0] = 'B';
		if(card[0] == 'R') card[0] = 'C';
		if(card[0] == 'Y') card[0] = 'D';
		if(card[0] == 'W') card[0] = 'E';
		c[card[0] - 'A'][card[1] - '1']++;
	}

	int ans = 99999;

	rep(m1, 1<<5) rep(m2, 1<<5) {
		int mxcnt = 0;

		rep(i, 5) if(!(m1 >> i & 1))
			rep(j, 5) if(!(m2 >> j & 1))
				if(c[i][j]) mxcnt++;
		
		rep(i, 5) if(m1 >> i & 1) {
			int cnt = 0;
			rep(j, 5) if(!(m2 >> j & 1))
				if(c[i][j]) cnt++;
			smax(mxcnt, cnt);
		}
		rep(j, 5) if(m2 >> j & 1) {
			int cnt = 0;
			rep(i, 5) if(!(m1 >> i & 1))
				if(c[i][j]) cnt++;
			smax(mxcnt, cnt);
		}
		if(mxcnt <= 1)
			smin(ans, __builtin_popcount(m1 | (m2 << 5)));
	}

	cout << ans << endl;

	{ return 0; }
}

