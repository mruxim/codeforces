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

const int maxn = 2000 + 100;

int n;
char s[maxn][maxn];
char r1[maxn], c1[maxn];
char r2[maxn], c2[maxn];
int ans;

int main()
{
	scanf ("%d ", &n);
	rep (i, n) gets (s[i]);
	rep (i, n) rep (j, n) s[i][j] -= '0';

	rep (i, n) rof (j, n, i+1)
		if (r1[i] ^ c1[j] ^ s[i][j])
			ans++, r1[i] ^= 1, c1[j] ^= 1;
	rof (i, n, 0) rep (j, i)
		if (r2[i] ^ c2[j] ^ s[i][j])
			ans++, r2[i] ^= 1, c2[j] ^= 1;
	rep (i, n)
		if (r1[i] ^ c1[i] ^ r2[i] ^ c2[i] ^ s[i][i])
			ans++;

	printf ("%d\n", ans);
	{ int _; cin >> _; }
}
