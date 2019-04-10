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

int n, x;
int s[5];
int ans = 0;

int rid (int &a, int &b) { int c = min (a, b); a -= c; b -= c; return c; }

int main()
{
	cin >> n;
	rep (i, n) cin >> x, s[x]++;
	ans += s[4];
	ans += rid (s[1], s[3]);
	ans += s[3];
	ans += s[2] / 2;
	s[2] %= 2;
	if (s[2]) { ans++; s[1] = max (0, s[1] - 2); }
	ans += (s[1]+3) / 4;
	cout << ans << endl;
	{ int _; cin >> _; }
}
