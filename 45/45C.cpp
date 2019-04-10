#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

const int MAXn = 2 * 100000 + 100;

int n;
char s[MAXn];
int a[MAXn];
int prv[MAXn], nxt[MAXn];
bool gone[MAXn];

struct couple
{
	int left, right;
	couple (int left, int right): left(left), right(right) {}
	bool operator < (couple X) const
	{
		return abs (a[left] - a[right]) == abs (a[X.left] - a[X.right]) ? left > X.left : abs (a[left] - a[right]) > abs (a[X.left] - a[X.right]);
	}
};

priority_queue <couple> pq;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		prv[i] = i-1, nxt[i] = i+1;

	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (s[i] == 'B');

	cout << min (cnt, n - cnt) << endl;

	for (int i = 0; i < n-1; i++)
		if (s[i] != s[i+1])
			pq.push (couple (i, i+1));

	while (!pq.empty())
	{
		int l = pq.top().left, r = pq.top().right;
		pq.pop();
		if (gone[l] || gone[r])
			continue;

		gone[l] = gone[r] = true;
		cout << l + 1 << ' ' << r + 1 << endl;

		l = prv[l], r = nxt[r];
		if (l != -1)
			nxt[l] = r;
		if (r != n)
			prv[r] = l;
		if (l != -1 && r != n && s[l] != s[r])
			pq.push (couple (l, r));
	}
	{ int _; cin >> _; }
}
