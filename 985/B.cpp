// .... ... .... .., ....!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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

const int maxn = 2000 + 10;

int n, m;
char c[maxn][maxn];
int sum[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> c[i];
	rep(i, n) rep(j, m) c[i][j] -= '0', sum[j] += c[i][j];

	rep(i, n) {
		bool yes = true;
		rep(j, m) if(sum[j] - c[i][j] == 0)
			yes = false;
		if(yes) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}

