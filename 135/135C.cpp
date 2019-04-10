#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s, t;
int n, o, z, q, a, b;
vector <string> res;

int main()
{
	cin >> s;
	n = (int)s.size();
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			z++;
		else if (s[i] == '1')
			o++;
	q = n - o - z;
	a = (n-2) / 2;
	b = (n-2) - a;
	if (o <= b)
		res.push_back ("00");
	if (z <= a)
		res.push_back ("11");
	if (o <= b+1 && z <= a+1)
	{
//		if (s[n-1] != '1')
		if (s[n-1] == '0' || (s[n-1] == '?' && z <= a))
			res.push_back ("10");
//		if (s[n-1] != '0')
		if (s[n-1] == '1' || (s[n-1] == '?' && o <= b))
			res.push_back ("01");
	}
	sort (res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << endl;
	{ int _; cin >> _; }
}
