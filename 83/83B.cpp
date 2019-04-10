#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 * 1000 + 100;

int n;
long long k, s;
pair <int, int> a[MAXn];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i+1, s += a[i].first;
	sort (a, a + n);

	long long z = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		int j = i+1;
		while (j < n && a[i].first == a[j].first)
			j++;
		long long t = i ? a[i-1].first : 0;
		z += ((long long)a[i].first - t) * (n - i);
		if (z > k)
		{
			z -= ((long long)a[i].first - t) * (n - i);
			t += (k - z) / (n - i);
//			z += (k - z) / (n - i) * (n - i);
			for (int p = i; p < n; p++)
				swap (a[p].first, a[p].second);
			sort (a + i, a + n);
			for (int p = i; p < n; p++)
//				if (a[i + (k - z + p) % (n - i)].second > t+1)
					cout << a[i + (k - z + p) % (n - i)].first << ' ';
			cout << endl;
			flag = true;
			break;
		}
		i = j-1;
	}
	if (!flag && s < k)
		cout << -1 << endl;
	{ int _; cin >> _; }
}
