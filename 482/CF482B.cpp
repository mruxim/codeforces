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

const int maxn = 100000 + 100;
const int mbit = 30;
const int nlog = 17 + 1;

int n, m;
int l[maxn], r[maxn], q[maxn];
int nx[mbit][maxn];
int val[maxn];
int f[nlog][maxn];
int t[maxn];

void fix(int bit, int l, int r) {
	for(int ind = l, tmp; ind < r; tmp = ind, ind = nx[bit][ind], nx[bit][tmp] = r)
		val[ind] |= 1 << bit;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;

	rep(bit, mbit) rep(i, n) nx[bit][i] = i+1;

	rep(i, m) {
		cin >> l[i] >> r[i] >> q[i]; l[i]--;
		rep(bit, mbit) if(q[i] >> bit & 1)
			fix(bit, l[i], r[i]);
	}

	rep(log, nlog) rep(i, n) {
		if(log == 0) f[log][i] = val[i];
		else {
			f[log][i] = f[log-1][i];
			if(i + (1 << (log-1)) < n)
				f[log][i] &= f[log-1][i + (1 << (log-1))];
		}
	}

	t[1] = 0;
	fer(i, 2, n+1) t[i] = t[i/2] + 1;

	rep(i, m) {
		int id = t[r[i] - l[i]];
		if((f[id][l[i]] & f[id][r[i] - (1<<id)]) != q[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	rep(i, n) cout << val[i] << ' ';
	cout << endl;

	return 0;
}

