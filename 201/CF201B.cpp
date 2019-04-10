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

const int maxn = 1000 + 100;

int n, m;
int a[maxn][maxn];

ll si[maxn], sj[maxn];
ll fsr[maxn], fsl[maxn], fsu[maxn], fsd[maxn];

int main()
{
	cin >> n >> m;
	rep (i, n) rep (j, m) cin >> a[i][j];
	
	rep (i, n) rep (j, m) si[i] += a[i][j], sj[j] += a[i][j];

	fer (i, 0, n+1) rep (k, i) fsu[i] += (2*(i-k)-1)*(2*(i-k)-1) * si[k];
	fer (j, 0, m+1) rep (k, j) fsl[j] += (2*(j-k)-1)*(2*(j-k)-1) * sj[k];
	rof (i, n+1, 0) rof (k, n, i) fsd[i] += (2*(k-i)+1)*(2*(k-i)+1) * si[k];
	rof (j, m+1, 0) rof (k, m, j) fsr[j] += (2*(k-j)+1)*(2*(k-j)+1) * sj[k];

	ll ans = 1ll<<60;
	int bx, by;
	rep (i, n+1) rep (j, m+1)
	{
		ll cur = fsu[i] + fsd[i] + fsl[j] + fsr[j];
		if(cur < ans)
			ans = cur, bx = i, by = j;
	}
	cout << 4*ans << endl;
	cout << bx << ' ' << by << endl;
	{ int _; cin >> _; }
}
