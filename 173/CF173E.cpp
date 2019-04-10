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
#define Y second.first
#define ID second.second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> tri;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 100 * 1000 + 100;

int n, k;
tri p[MAXn];
int rID[MAXn];
int ages[MAXn], ac;
int cnt[4*MAXn];
int ldr[MAXn];

int Q;
tri q[MAXn];
int val[4*MAXn];
int ans[MAXn];

bool cmp (const tri &A, const tri &B)
{
	return max (p[A.X].X, p[A.Y].X) < max (p[B.X].X, p[B.Y].X);
}

void add (int x, int l, int r, int pos)
{
	if (pos < l || r <= pos) return;
	cnt[x]++;
	if (r - l == 1) return;
	int m = (l + r) / 2;
	add (2*x+1, l, m, pos);
	add (2*x+2, m, r, pos);
}

int req (int x, int l, int r, int p, int q)
{
	if (q <= l || r <= p) return 0;
	if (p <= l && r <= q) return cnt[x];
	int m = (l + r) / 2;
	return req (2*x+1, l, m, p, q) + req (2*x+2, m, r, p, q);
}

void add2 (int x, int l, int r, int pos, int v)
{
	if (pos < l || r <= pos) return;
	cmx (val[x], v);
	if (r - l == 1) return;
	int m = (l + r) / 2;
	add2 (2*x+1, l, m, pos, v);
	add2 (2*x+2, m, r, pos, v);
}

int req2 (int x, int l, int r, int p, int q)
{
	if (q <= l || r <= p) return 0;
	if (p <= l && r <= q) return val[x];
	int m = (l + r) / 2;
	return max (req2 (2*x+1, l, m, p, q), req2 (2*x+2, m, r, p, q));
}

int main()
{
	cin >> n >> k;
	rep (i, n) cin >> p[i].X;
	rep (i, n) cin >> p[i].Y;
	rep (i, n) p[i].ID = i;

	sort (p, p + n);
	rep (i, n) rID[p[i].ID] = i;

	rep (i, n) ages[i] = p[i].Y;
	sort (ages, ages + n);
	ac = unique (ages, ages + n) - ages;

	rep (i, n)
	{
		int j = i;
		while (j < n && p[j].X == p[i].X)
		{
			add (0, 0, ac, lower_bound (ages, ages + ac, p[j].Y) - ages);
			j++;
		}
		for (; i < j; i++)
		{
			int L = lower_bound (ages, ages + ac, p[i].Y - k) - ages, R = upper_bound (ages, ages + ac, p[i].Y + k) - ages;
			ldr[i] = req (0, 0, ac, L, R);
//			cout << " ** " << i << ' ' << ldr[i] << ' ' << L << ' ' << R << endl;
		}
		i--;
	}

	cin >> Q;
	rep (i, Q)
	{
		cin >> q[i].X >> q[i].Y;
		q[i].X--, q[i].Y--;
		q[i].X = rID[q[i].X], q[i].Y = rID[q[i].Y];
		if (p[q[i].X].Y > p[q[i].Y].Y) swap (q[i].X, q[i].Y);
//		cout << " $$ " << q[i].X << ' ' << q[i].Y << endl;
		q[i].ID = i;
	}
	sort (q, q + Q, cmp);

	int pos = n;
	for (int i = Q; i--; )
	{
		int mxr = max (p[q[i].X].X, p[q[i].Y].X);
		while (pos && p[pos-1].X >= mxr) --pos, add2 (0, 0, ac, lower_bound (ages, ages + ac, p[pos].Y) - ages, ldr[pos]);
		int L = lower_bound (ages, ages + ac, p[q[i].Y].Y - k) - ages, R = upper_bound (ages, ages + ac, p[q[i].X].Y + k) - ages;
		if (R - L > 0)
			ans[q[i].ID] = req2 (0, 0, ac, L, R);
		if (ans[q[i].ID] == 0)
			ans[q[i].ID] = -1;
	}

	rep (i, Q)
		cout << ans[i] << endl;

	{ int _; cin >> _; }
}
