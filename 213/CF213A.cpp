// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
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

const int maxn = 200 + 10;

int n;
int c[maxn];
vi a[maxn];
int k[maxn], deg[maxn];

int solve (int x)
{
	rep (z, n) rep (i, n) if (deg[i] == 0 && c[i] == x) // rep (z, n) = tof!
	{
		deg[i] = -1;
		fch (it, a[i])
			deg[*it]--;
	}
	int done = 0;
	rep (i, n) if (deg[i] == -1) done++;
	if (done == n) return 0;
	return 1 + solve ((x+1)%3);
}

int main()
{
	cin >> n;
	rep (i, n) cin >> c[i], c[i]--;
	rep (i, n)
	{
		cin >> k[i];
		rep (j, k[i])
		{
			int x;
			cin >> x; x--;
			a[x].pb (i);
		}
	}

	int ans = 1<<30;
	rep (i, 3)
	{
		memcpy (deg, k, sizeof k);
//		rep (i, n) cerr << deg[i] << ' '; cerr << endl;
		int z;
		cmn (ans, z = solve (i));
//		cerr << z << endl;
	}
	cout << n + ans << endl;
	{ int _; cin >> _; }
}
