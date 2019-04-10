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

int hp1, at1, df1;
int hp2, at2, df2;
int h, a, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> hp1 >> at1 >> df1;
	cin >> hp2 >> at2 >> df2;
	cin >> h >> a >> d;

	int ans = 1 << 29;

	rep(dd, 1111) rep(aa, 1111) {
		int cost = aa*a + dd*d;
		int dmg1 = max(0, at2 - df1 - dd);
		int dmg2 = max(0, at1 + aa - df2);

		if(dmg2 == 0) continue;
		if(dmg1 == 0) smin(ans, cost);
		else {
			int addh = 1 + dmg1 * ((hp2 + dmg2 - 1) / dmg2) - hp1;
			smin(ans, cost + h * max(0, addh));
		}
	}

	cout << ans << endl;

	return 0;
}

