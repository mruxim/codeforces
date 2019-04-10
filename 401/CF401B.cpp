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

const int maxx = 4000 + 100;

int x, k;
int mark[maxx];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> x >> k;
	mark[x-1] = 1;

	rep(i, k) {
		int t; cin >> t; t = 3 - t;
		rep(j, t) { int p; cin >> p; mark[p-1] = 1; }
	}

	int ans2 = count(mark, mark+x, 0);

	int ans1 = 0;
	int cnt = 0;
	rep(i, x)
		if(mark[i])
			ans1 += (cnt + 1) / 2, cnt = 0;
		else
			cnt++;

	cout << ans1 << ' ' << ans2 << endl;

	{ return 0; }
}

