#include <iostream>
#include <algorithm>

using namespace std;

const int MAXn = 100;

int n;
pair <pair <int, int>, int> a[MAXn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	sort (a, a + n);
	for (int i = 1; i < n; i++)
		while (a[i].first.first == a[i-1].first.first)
		{
			a[i].first.first++;
			for (int j = i+1; j < n && a[j-1] > a[j]; j++)
				swap (a[j-1], a[j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[j].second == i)
				cout << a[j].first.first << ' ';
	cout << endl;
	{ int _; cin >> _; }
}
