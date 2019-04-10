#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define F first
#define S second
#define P_B push_back
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define FR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define debug(x) cerr<< #x << ": " << x << endl;
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000 * 100 + 10;
ll t[MAXN], num[MAXN], pw[MAXN];
bool mark[MAXN], mark2[MAXN];

int main()
{
	int n;
	cin>> n;
	int mx = 0;
	FR(j, 0, n)
	{
		int a;
	//	cin>> a;
		a = j+1;
		FR(i, 1, sqrt(a))
			if(a % i == 0)
			{
				t[i]++;
				t[a / i]++;
			}
		if(sqrt(a) - (int)sqrt(a) == 0)
			t[(int)sqrt(a)] ++;
		mx = max(mx, a + 1);
	}

	mark[0] = mark[1] = true;
	FR(i, 2, mx)
		if(!mark[i])
			for(int j = i + i; j < mx; j += i)
			{
				mark[j] = true;
				if(j % (i * i) == 0)
					mark2[j] = true;
			}

	FR(i, 2, mx)
	{
		FR(j, 1, sqrt(i))
			if(i % j == 0)
			{
				if(!mark[j]) num[i]++;
				if(!mark[i / j] && j != i / j) num[i]++;
			}
		if(sqrt(i) - (int)sqrt(i) == 0 && !mark[(int)sqrt(i)])
			num[i]++;
	}
			
	pw[0] = 1;
	FR(i, 1, n + 1)
		pw[i] = (pw[i - 1] * 2) % mod;

	ll ans = 1;
	FR(i, 2, mx)
		if(!mark2[i])
	{
		if(num[i] % 2) ans = (ans + pw[t[i]] - 1) % mod;
		else ans = (ans + mod - pw[t[i]] + 1) % mod;
/*		if(num[i] % 2) ans = (ans + pw[t[i]] - 1);
		else ans = (ans - pw[t[i]] + 1);
		if(t[i]  != 0)
		{
		cout<< i << " " << t[i] << " " << ans << endl;
		cout<< num[i] << endl;
		}
*/	}
//	cout<< pw[n] << " " << ans << endl;
	cout<< ((pw[n] + mod - ans) % mod) << endl;
	
	return 0;
}
