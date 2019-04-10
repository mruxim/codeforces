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

////////////////////////////////////////////////

const int MAXn = 100 + 100;

int n;
int a[MAXn], s[MAXn];

int main()
{
	cin >> n;
	rep (i, n) cin >> a[i];
	a[n++] = 99999;
	sort (a, a + n);
	s[0] = 10;
	rep (i, n)
		s[i+1] = s[i] + a[i];
	int res = 0, pen = 0;
	rep (i, n)
		res += (s[i+1] <= 720) ? 1 : 0,
		pen += (s[i+1] <= 720) ? max (0, s[i+1] - 360) : 0;
	cout << res << ' ' << pen << endl;
	{ int _; cin >> _; }
}
