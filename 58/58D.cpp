#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXn = 10000 + 100;

int n;
string s[MAXn];
string sep;

bool cmp (const string &s1, const string &s2)
{
	return s1 + sep + s2 < s2 + sep + s1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	cin >> sep;
	sort (s, s + n, cmp);
	for (int i = 0; i < n/2; i++)
		cout << s[2*i] << sep << s[2*i+1] << endl;
	{ int _; cin >> _; }
}
