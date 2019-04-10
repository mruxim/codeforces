#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

const int MAXn = 5 * 100 * 1000 + 100;

int n;
long long x[MAXn], v[MAXn];
int s[MAXn], h, t;
double res = 1e20;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> v[i];
		if (v[i] > 0)
		{
			while (t > h && v[s[t-1]] <= v[i]) t--;
			s[t++] = i;
		}
		else
		{
			while (h+1 < t && (x[i] - x[s[h]]) * (-v[i] + v[s[h+1]]) >= (x[i] - x[s[h+1]]) * (-v[i] + v[s[h]]))
				h++;
			if (h < t)
				res = min (res, (double)(x[i] - x[s[h]]) / (double)(-v[i] + v[s[h]]));
		}
	}
	if (res > 1e19)
		puts ("-1");
	else
		printf ("%.15lf\n", res);
	{ int _; cin >> _; }
}
