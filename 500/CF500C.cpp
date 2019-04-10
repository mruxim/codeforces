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

const int maxn = 500 + 100;
const int maxm = 1000 + 100;

int n, m;
int w[maxn];
int b[maxm];
bool mark[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> w[i];
	rep(i, m) cin >> b[i], b[i]--;

	int ans = 0;
	rep(i, m) {
		memset(mark, 0, sizeof mark);
		rof(j, i, 0) {
			if(b[j] == b[i]) break;
			if(!mark[b[j]])
				ans += w[b[j]], mark[b[j]] = 1;
		}
	}

	cout << ans << endl;

	return 0;
}

