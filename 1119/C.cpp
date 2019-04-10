// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500 + 10;

int n, m;
int a[maxn][maxn], b[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	rep(i, n) rep(j, m) cin >> b[i][j];

	rep(i, n) rep(j, m) a[i][j] ^= b[i][j];

	bool yes = true;
	rep(i, n) {
		int cnt = 0;
		rep(j, m) cnt += a[i][j];
		yes &= (cnt % 2 == 0);
	}

	rep(j, m) {
		int cnt = 0;
		rep(i, n) cnt += a[i][j];
		yes &= (cnt % 2 == 0);
	}

	cout << (yes ? "Yes" : "No") << endl;

	return 0;
}

