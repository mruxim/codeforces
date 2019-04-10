#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 1000 + 10;

int n;
int a[MAXn];
int l[MAXn], r[MAXn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] >= a[i-1])
			l[i] = l[i-1] + 1;
		else
			l[i] = 0;
	for (int i = n-1; i--; )
		if (a[i] >= a[i+1])
			r[i] = r[i+1] + 1;
		else
			r[i] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max (ans, l[i] + r[i]);
	cout << ans + 1 << endl;
	{ int _; cin >> _; }
}
