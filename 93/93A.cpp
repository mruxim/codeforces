#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(x) x.begin(), x.end()
#define cmax (a, b) a = max(a,b)
#define cmin (a, b) a = min(a,b)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

////////////////////////////////////////////////

int n, m, a, b;

int main()
{
	cin >> n >> m >> a >> b;
	a--;
	if (b == n) b = (b-1) / m * m + m;
	int t;
	if (a / m == (b-1) / m || (a % m == 0 && b % m == 0))
		t = 1;
	else if ((b - a) % m == 0 || a % m == 0 || b % m == 0 || (b-1) / m - a / m <= 1)
		t = 2;
	else t = 3;
	cout << t << endl;
	{ int _; cin >> _; }
}
