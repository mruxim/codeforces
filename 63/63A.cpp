#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAXn = 100 + 10;

int n;
pair <int, string> p[MAXn];
string t;

bool cmp (const pair <int, string> a, const pair <int, string> b)
{
	return a.first < b.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].second >> t;
		p[i].first = t=="rat" ? 0 : t=="woman"||t=="child" ? 1 : t=="man" ? 2 : 3;
	}
	stable_sort (p, p + n, cmp);
	for (int i = 0; i < n; i++)
		cout << p[i].second << endl;
	{ int _; cin >> _; }
}
