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

inline int nextInt () {
	register char ch;
	register int res;
	while((ch = getchar()) < '0');
	for(res = ch - '0'; (ch = getchar()) >= '0'; res = res * 10 + ch - '0');
	return res;
}
////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000000+100;

int n, q;
int a[maxn];

int main() {
	cin >> n >> q;
	rep(i, n) a[i] = nextInt();

	rep(i, q) {
		ll b; cin >> b;

		register ll rem = 0;
		register int ans = 0;

		rep(i, n)
			if(rem < a[i]) rem = b - a[i], ans++;
			else rem -= a[i];

		cout << ans << endl;
	}
	return 0;
}

