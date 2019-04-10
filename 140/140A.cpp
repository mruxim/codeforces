#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

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

int n;
double R, r, h;

int main()
{
	cin >> n >> R >> r;
	h = asin (r / (R - r));
	if (r > R) { cout << "NO" << endl; return 0; }
	if (r > R/2)
	{
		cout << (n == 1 ? "YES" : "NO") << endl;
		return 0;
	}
	if (M_PI / h + 1e-10 >= (double)n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	{ int _; cin >> _; }
}
