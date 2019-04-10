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

const int maxn = 100000 + 100;

int n;
int a[maxn];
int l[maxn], r[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	r[n-1] = 1;
	rof(i, n-1, 0)
		if(a[i] < a[i+1])
			r[i] = r[i+1] + 1;
		else
			r[i] = 1;

	l[0] = 1;
	fer(i, 1, n)
		if(a[i] > a[i-1])
			l[i] = l[i-1] + 1;
		else
			l[i] = 1;

	int ans = 2;
	fer(i, 1, n-1) if(a[i-1] + 1 < a[i+1])
		smax(ans, l[i-1] + r[i+1] + 1);

	fer(i, 1, n) smax(ans, 1 + l[i-1]);
	rep(i, n-1) smax(ans, 1 + r[i+1]);

	cout << min(n, ans) << endl;

	{ return 0; }
}

