
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

const int maxn = 100 + 100;

int n;
int ciel, jiro;
vector<int> mid;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) {
		int k;
		cin >> k;
		vector<int> v(k);
		rep (j, k) cin >> v[j];
		ciel += accumulate (v.begin(), v.begin() + k/2, 0);
		jiro += accumulate (v.end() - k/2, v.end(), 0);
		if (k % 2 == 1) mid.pb (v[k/2]);
	}
	sort (all(mid), greater<int>());
	rep (i, sz(mid))
		if (i % 2 == 0) ciel += mid[i];
		else jiro += mid[i];

	cout << ciel << ' ' << jiro << endl;

	{ return 0; }
}

