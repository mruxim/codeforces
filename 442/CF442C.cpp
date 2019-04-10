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

const int maxn = 500000 + 100;
const int maxlg = 20;

int n;
int a[maxn];
int pr[maxn], ne[maxn];

struct cmp {
	bool operator()(int x, int y) {
		return a[x] != a[y] ? a[x] < a[y] : x < y;
	}
};

set<int, cmp> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	rep(i, n-1) pr[i+1] = i, ne[i] = i+1;
	pr[0] = -1, ne[n-1] = -1;
	rep(i, n) s.insert(i);

	ll ans = 0;
	int sub = 0;

	rof(rem, n+1, 2) {
		int pos = *s.begin();
		s.erase(pos);
		
		int c = 0;
		if(pr[pos] != -1) ne[pr[pos]] = ne[pos], c++;
		if(ne[pos] != -1) pr[ne[pos]] = pr[pos], c++;

		if(c == 2) ans += min(a[pr[pos]], a[ne[pos]]) - sub;
		else ans += (a[pos] - sub) * (ll)(rem - 2), sub = a[pos];
	}

	cout << ans <<  endl;


	{ return 0; }
}

