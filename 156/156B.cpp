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

const int MAXn = 100 * 1000 + 999;

int n, m;
int f[MAXn];
int ina[MAXn];
int inb[MAXn];
int mit[MAXn];
int a, b;

int main()
{
	cin >> n >> m;
	rep (i, n)
	{
		char c;
		cin >> c;
		if (c == '+') a++; else b++;
		cin >> f[i];
		if (c == '-') f[i] *= -1;
		if (f[i] > 0)	ina[f[i]]++;
		else			inb[-f[i]]++;
	}
	int tm = 0;
	fer (i, 1, n+1)
	{
		int tr = ina[i] + b - inb[i];
		if (tr == m) mit[i] = 1;
		tm += mit[i];
	}
	rep (i, n)
	{
		bool mrg, mdg;
		if (f[i] > 0)
			mrg = mit[f[i]], mdg = (tm>=2 || (tm==1 && !mit[f[i]]));
		else
		{
			f[i] *= -1;
			mrg = (tm>=2 || (tm==1 && !mit[f[i]])), mdg = mit[f[i]];
		}
		if (mrg && !mdg)
			cout << "Truth" << endl;
		else if (!mrg && mdg)
			cout << "Lie" << endl;
		else
			cout << "Not defined" << endl;
	}
	{ int _; cin >> _; }
}
