#include <iostream>

using namespace std;

double eps = 1e-10;

int n;
double a[2000];
double mn, mx;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mn = 0, mx = 999999999.0;
	for (int i = 0; i < n; i++)
		mn = max (mn, a[i] / (double)(i + 1)), mx = min (mx, (a[i] + 1) / (double)(i + 1));
	if ((int)((double)(n+1) * mn) == (int)((double)(n+1) * mx - eps))
	{
		cout << "unique\n";
		cout << (int)((double)(n+1) * mn) << endl;
	}
	else
		cout << "not unique\n";
	{ int _; cin >> _; }
}
