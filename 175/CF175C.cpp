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
typedef pair <ll, ll> pll;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 100 + 20;

int n, t;
pll f[MAXn];
ll p[MAXn];
ll ans;

int main()
{
	cin >> n;
	rep (i, n) cin >> f[i].Y >> f[i].X;
	cin >> t;
	rep (i, t) cin >> p[i];
	p[t] = 1LL << 62;

	sort (f, f + n);

	ll des = 0;
	int cur = 0;

	rep (i, n)
	{
		while (f[i].Y)
		{
			if (des + f[i].Y < p[cur])
			{
				des += f[i].Y, ans += f[i].Y * f[i].X * (cur + 1);
				break;
			}
			ans += (p[cur] - des) * f[i].X * (cur + 1), f[i].Y -= p[cur] - des, des = p[cur], cur++;
		}
	}


	cout << ans << endl;

	{ int _; cin >> _; }
}
