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

const int MAXn = 20000 + 999;

int n;
int a[MAXn];
int ans = -(1<<30);

int main()
{
	cin >> n;
	rep (i, n) cin >> a[i];
	for (int i = 1; 2*i < n; i++) if (n % i == 0)
	{
		rep (j, i)
		{
			int c = 0;
			for (int k = j; k < n; k += i)
				c += a[k];
			cmx (ans, c);
		}
	}
	cout << ans << endl;
	{ int _; cin >> _; }
}
