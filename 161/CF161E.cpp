// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i <= _n; i++)
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

const int MAXp = 100000;

int p, d;
int p10[8];
int dig[8];
bool ip[MAXp];
int num[8];
//vi v[5][5][MAXp];
vi v[6][10][6][MAXp/100];
int ans = 0;

void init ()
{
	p10[0] = 1; for (int i = 1; i < 8; i++) p10[i] = p10[i-1] * 10;
	ip[0] = ip[1] = 1;
	for (int i = 2; i < MAXp; i++) if (!ip[i])
	{
		fer (d, 1, 5) fer (y, 0, min(d,3)) if (i/p10[d-1] < 10) v[d][i/p10[d-1]][y][i%p10[y]].pb (i);
		if (i < 1000)
			for (ll j = i*i; j < MAXp; j += i) ip[j] = 1;
	}
}

void bt (int r)
{
	if (r == 0) { ans++; return; }
	vi &f = v[d][dig[r]][d-r-1][num[r]];
	int z = sz(f);
	int c = d - r - 1;
	rep (i, z)
	{
		int x = f[i];
		fer (j, 1, r-1) num[j] += (x / p10[d-j-1] % 10) * p10[c];
		bt (r-1);
		fer (j, 1, r-1) num[j] -= (x / p10[d-j-1] % 10) * p10[c];
	}
}

int main()
{
	init ();

	int ts;
	for (cin >> ts; ts--; )
	{
		cin >> p;


		int tmp = p; d = 0; while (tmp) dig[d++] = tmp % 10, tmp /= 10;
		reverse (dig, dig+d);

		ans = 0;
		bt (d-1);
		cout << ans << endl;
	}
	{ int _; cin >> _; }
}
