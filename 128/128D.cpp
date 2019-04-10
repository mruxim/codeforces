#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 * 1000 + 100;

int n;
int a[MAXn];
int r[MAXn];
int m;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	m = a[0];
	for (int i = 0; i < n; i++)
		a[i] -= m;
	m = a[n-1];
	if (n % 2 == 1 || n / 2 < m)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		r[a[i]]++;
	for (int i = 0; i < m; i++)
		r[i]--, r[i+1]--;
	for (int i = 0; i <= m; i++)
		if (r[i] < 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	for (int i = 0; i < m; i++)
	{
		int x = min (r[i], r[i+1]);
		r[i] -= x;
		r[i+1] -= x;
	}
	for (int i = 0; i <= m; i++)
		if (r[i] > 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	{ int _; cin >> _; }
}
