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

const int maxn = 1000 * 1000 + 100;

int n, q, m;
char s[maxn], t[maxn];
int c[128], p[128][128];

int main()
{
	gets (s), n = strlen (s);
	int k = 0;
	rep (i, n)
		if (i == 0 || s[i] != s[i-1])
			s[k++] = s[i];
	n = k;
	rep (i, n)
		c[s[i]]++;
	rep (i, n-1)
		p[s[i]][s[i+1]]++;
	for (scanf ("%d ", &q); q--; )
	{
		gets (t), m = strlen (t);
		sort (t, t + m);
		m = unique (t, t + m) - t;
		int ans = 0;
		rep (i, m)
		{
			ans += c[t[i]];
			rep (j, i)
				ans -= p[t[j]][t[i]] + p[t[i]][t[j]];
		}
		printf ("%d\n", ans);
	}
	{ int _; cin >> _; }
}
