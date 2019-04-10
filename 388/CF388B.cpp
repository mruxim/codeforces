
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

bool g[555][555];


int main()
{
	ios_base::sync_with_stdio (false);

	int k;
	cin >> k;

	if (k == 1) {
		cout << 2 << endl;
		cout << "NY" << endl;
		cout << "YN" << endl;
		return 0;
	}

	int b = 1;
	while (b*2 <= k) b *= 2; b /= 2;

	int n = 0;
	while (b) {
		int a = 5*n;
		g[a][a+3] = g[a+3][a] = 1;
		g[a+3][a+5] = g[a+5][a+3] = 1;
		int p = max (0, a-1);
		g[p][a+1] = g[a+1][p] = 1;
		g[p][a+2] = g[a+2][p] = 1;
		g[a+1][a+4] = g[a+4][a+1] = 1;
		g[a+2][a+4] = g[a+4][a+2] = 1;
		if (k & b) g[a+3][a+4] = g[a+4][a+3] = 1;
		n++;
		b /= 2;
	}

	cout << 5*n << endl;
	rep (i, 5*n) {
		rep (j, 5*n) {
			int ii = i, jj = j;
			if (ii == 1 || ii == 5*n-1) ii = 5*n - ii;
			if (jj == 1 || jj == 5*n-1) jj = 5*n - jj;
			cout << (g[ii][jj] ? 'Y' : 'N');
		}
		cout << endl;
	}



	{ return 0; }
}

