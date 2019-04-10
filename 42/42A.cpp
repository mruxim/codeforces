#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
double v;
double a[200], b[200], s;
double res;

int main()
{
	cin >> n >> v;
	for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	res = v;
	for (int i = 0; i < n; i++)
		res = min (res, b[i] * s / a[i]);
	cout << res << endl;
	{ int _; cin >> _; }
}
