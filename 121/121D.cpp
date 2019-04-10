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

const int maxn = 100000 + 100;

int n;
ll k;
pair <ll, ll> a[maxn];
ll lucky[1 << 19];
int len;
ll lsum[maxn], rsum[maxn];

void add (int x)
{
	ll r = 0, p10 = 1;
	while (x > 1)
		r += (x % 2 ? 7 : 4) * p10, p10 *= 10, x /= 2;
	lucky[len++] = r;
}

boo cmpx (const pair <ll, ll> &A, const pair <ll, ll> &B) { return A.X > B.X; }
boo cmpy (const pair <ll, ll> &A, const pair <ll, ll> &B) { return A.Y < B.Y; }

int main()
{
	ios::sync_with_stdio (false);

	fer (i, 2, 1 << 19) add (i);

	cin >> n >> k;
	rep (i, n) cin >> a[i].X >> a[i].Y;

	int p, q;
	
	sort (a, a + n, cmpy); p = 0;
	rep (i, len)
	{
		if (i) lsum[i] = lsum[i-1] + p * (lucky[i] - lucky[i-1]);
		while (p < n && a[p].Y <= lucky[i])
			lsum[i] += lucky[i] - a[p].Y, p++;
	}
	sort (a, a + n, cmpx); p = 0;
	rof (i, len, 0)
	{
		if (i<len-1) rsum[i] = rsum[i+1] + p * (lucky[i+1] - lucky[i]);
		while (p < n && a[p].X >= lucky[i])
			rsum[i] += a[p].X - lucky[i], p++;
	}

	



	{ int _; cin >> _; }
}
