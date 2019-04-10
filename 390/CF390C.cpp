
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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, k, w;
string s;
int sum[maxn];
int f[maxn];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k >> w;
	cin >> s;
	rep (i, n) sum[i+1] = sum[i] + s[i] - '0';
	fer (i, 1, n+1) {
		f[i] = (s[i-1] == '0' ? 1 : 0);
		int p = max (0, i-k);
		f[i] += f[p] + sum[i-1] - sum[p];
	}

	while (w-- > 0) {
		int l, r;
		cin >> l >> r;
		cout << f[r] - f[l-1] << endl;
	}

	{ return 0; }
}

