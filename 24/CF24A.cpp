#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 + 5;

int n;
int a[MAXn], b[MAXn], w[MAXn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
	}
	int p = -1, c = 0, r1 = 0, r2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if ((a[j] == c || b[j] == c) && a[j] + b[j] - c != p)
			{
				p = c, c = a[j] + b[j] - c;
				if (a[j] == p)
					r1 += w[j];
				break;
			}
	}
	p = -1, c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j--; )
			if ((a[j] == c || b[j] == c) && a[j] + b[j] - c != p)
			{
				p = c, c = a[j] + b[j] - c;
				if (a[j] == p)
					r2 += w[j];
				break;
			}
		
	}
	cout << min (r1, r2) << endl;
	{ int _; cin >> _; }
}
