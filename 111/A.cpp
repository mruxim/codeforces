// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

ll n;
ll x, y;

int main()
{
	cin >> n >> x >> y;
	ll r = (y-n+1) * (y-n+1) + (n-1);
	if (y >= n && r >= x)
	{
		cout << y-n+1;
		rep (i, n-1)
			cout << ' ' << 1;
		cout << endl;
	}
	else
		cout << -1 << endl;
	{ int _; cin >> _; }
}
