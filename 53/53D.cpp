#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int a[1000], b[1000];
int r, x[1000000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		int p;
		for (p = i; b[p] != a[i]; p++);
		for (int j = p; j > i; j--)
		{
			swap (b[j], b[j-1]);
			x[r++] = j;
		}
	}
	cout << r << endl;
	for (int i = 0; i < r; i++)
		cout << x[i] << ' ' << x[i]+1 << endl;
	{ int _; cin >> _; }
}
