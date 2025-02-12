#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 * 1000 + 100;

int n, m;
pair <int, string> a[MAXn];
int b[MAXn];
string vas;

int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
		a[i].first *= -1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cin >> vas;

	sort (a, a + n);
	sort (b, b + n);

	int v;
	for (int i = 0; i < n; i++)
		if (a[i].second == vas)
			v = i;
	a[v].first -= b[0];
	int k = 1;
	int p = 0, q = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == v) continue;
		while (k < n && a[v] < make_pair (a[i].first - b[k], a[i].second))
			k++;
		if (k == n)
			break;
		p++, k++;
	}
	a[v].first += b[0];
	a[v].first -= b[n-1];
	k = n-2;
	for (int i = n; i--; )
	{
		if (i == v) continue;
		while (k >= 0 && a[v] > make_pair (a[i].first - b[k], a[i].second))
			k--;
		if (k < 0)
			break;
		q++, k--;
	}
	cout << n - q << ' ' << p + 1 << endl;
	{ int _; cin >> _; }
}
