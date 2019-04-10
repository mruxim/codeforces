// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>

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

const int maxn = 100000 + 1000;

int n, k;
ll b;
int a[maxn];
multiset <int> s;
ll sum;


int main()
{
	cin >> n >> k;
	cin >> b;
	rep (i, n) cin >> a[i];

	if (n == 1) { cout << 1 << endl; return 0; }

	int ans = n;

	rof (i, n-1, 0)
	{
		if (b - sum < (ll)a[i]) ans = i+1;
		s.insert (a[i]);
		sum += (ll)a[i];
		if ((int)s.size() >= k)
			sum -= *s.begin(), s.erase (s.begin());
	}

	cout << ans << endl;

	{ int _; cin >> _; }
}
