#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define all(x) x.begin(), x.end()
#define siz(x) int((x).size())
#define cmax (a, b) a = max(a,b)
#define cmin (a, b) a = min(a,b)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 100 * 1000 + 100;

int n;
int a[MAXn];
pii b[MAXn];
int t;

pii exMax ()
{
	if (n == 0) return pii (0, 0);
	pii res = b[0];
	b[0] = b[--n];
	for (int c = 0; 1; )
	{
		int l = 2*c+1, r = 2*c+2;
		if (l >= n) break;
		if (r < n)
			if (b[l].first < b[r].first)
				swap (l, r);
		if (b[l].first > b[c].first)
			swap (b[l], b[c]), c = l;
		else
			break;
	}
	return res;
}

void push (pii p)
{
	int c = n++;
	b[c] = p;
	while (c && b[(c-1)/2].first < b[c].first)
		swap (b[(c-1)/2], b[c]), c = (c-1) / 2;
}

int main()
{
	cin >> n;
	rep (i, n) cin >> a[i];
	sort (a, a + n);
	t = -1;
	rep (i, n)
		if (i && a[i] == a[i-1])
			b[t].first++;
		else
			b[++t].first++, b[t].second = a[i];
	n = t+1;
	sort (b, b + n);
	reverse (b, b + n);
	int ans = 0;
	vi q, w, e;
	while (1)
	{
		pii x = exMax ();
		pii y = exMax ();
		pii z = exMax ();
		if (z.first == 0) break;
		ans++;
		q.pb (x.second), w.pb (y.second), e.pb (z.second);
		if (x.first>1) push (mp (x.first - 1, x.second));
		if (y.first>1) push (mp (y.first - 1, y.second));
		if (z.first>1) push (mp (z.first - 1, z.second));
	}
	cout << ans << endl;
	rep (i, ans)
		cout << max (max (q[i], w[i]), e[i]) << ' ' << q[i]+w[i]+e[i] - max (max (q[i], w[i]), e[i]) - min (min (q[i], w[i]), e[i]) << ' ' << min (min (q[i], w[i]), e[i]) << endl;
	{ int _; cin >> _; }
}
