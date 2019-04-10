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

const int lim = 2000000 + 100;
const int maxn = 200000 + 100;


int n;
int a[maxn];
int dis[lim];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	fill(dis, dis + lim, 1e8);

	cin >> n;
	rep(i, n) cin >> a[i], dis[a[i]] = 0;

	int ans = 0;
	fer(i, 1, lim) dis[i] = min(dis[i], dis[i-1] + 1);

	fer(i, 2, lim) if(dis[i] == 0) {
		for(int j = i+i; j < lim; j += i)
			if(dis[j-1] < i)
				smax(ans, i - dis[j-1] - 1);
	}

	cout << ans << endl;

	return 0;
}

