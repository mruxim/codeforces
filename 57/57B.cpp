#include <iostream>

using namespace std;

const int MAXm = 100000 + 10;

int n, m, k;
int a[MAXm], b[MAXm], c[MAXm];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i] >> c[i];
	long long ans = 0;
	while (k--)
	{
		int p;
		cin >> p;
		for (int i = 0; i < m; i++)
			if (a[i] <= p && p <= b[i])
				ans += (long long)(p - a[i] + c[i]);
	}
	cout << ans << endl;
	{ int _; cin >> _; }
}
