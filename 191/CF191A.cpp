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

const int maxn = 500000 + 1000;

int n;
char a[maxn], b[maxn];
int l[maxn];
char tmp[22];

int dp[27][27];
int d[27];

int main()
{
	cin >> n;
	rep (i, n)
	{
		cin >> tmp;
		l[i] = strlen (tmp);
		a[i] = tmp[0] - 'a';
		b[i] = tmp[l[i]-1] - 'a';
	}
	
	memset (dp, -20, sizeof dp);
	
	rep (i, n)
	{
		rep (j, 26)
			d[j] = dp[j][a[i]] + l[i];
		rep (j, 26)
			cmx (dp[j][b[i]], d[j]);
		cmx (dp[a[i]][b[i]], l[i]);
	}
	
	int ans = 0;
	rep (i, 26)
		cmx (ans, dp[i][i]);
	
	cout << ans << endl;
	
	{ int _; cin >> _; }
}
