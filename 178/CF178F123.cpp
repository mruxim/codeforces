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

const int INF = 1 << 30;
const int maxN = 2000 + 100;

int n, k;
string s[maxN];
int diff[maxN];

vi solve (int l, int r)
{
	if (r - l == 1) return vi (2, 0);
	int m = min_element (diff + l + 1, diff + r) - diff;
	vi a = solve (l, m), b = solve (m, r);
	vi res (r - l + 1, 0);
	rep (i, sz (a)) rep (j, sz (b))
		cmx (res[i + j], a[i] + b[j] + i * j * diff[m]);
	return res;
}

int main()
{
	cin >> n >> k;
	rep (i, n) cin >> s[i];
	sort (s, s + n);
	rep (i, n-1)
		diff[i+1] = mismatch (all (s[i]), s[i+1].begin()).first - s[i].begin();

	cout << solve (0, n)[k] << endl;

	{ int _; cin >> _; }
}
