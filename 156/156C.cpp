#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=100+20 , MAXS=2600+200;
long long d[MAXN][MAXS];
#define M 1000ll * 1000 * 1000+7

int main()
{
    int t;
    cin>>t;

    for (int i=0 ; i<t ; i++)
    {
        long long sum=0;
        string s;
        cin>>s;
        for (int i=0 ; i<s.size() ; i++)
            sum+=s[i]-'a'+1;

        for (int i=0 ; i<s.size() ; i++)
            for (int j=i+1 ; j<=sum ; j++)
            {
                for (int k=1 ; k<=min(j,26) ; k++)
                {
                    if (i==0 && j<=26) d[i][j]=1;
                    else d[i][j]+=d[i-1][j-k];
                    d[i][j]%=M;
                }
             }

        cout<<d[s.size()-1][sum]-1<<endl;

        for (int i=0 ; i<MAXN ; i++)
            for (int j=0 ; j<=sum ; j++)
                d[i][j]=0;
    }
	cin >> t;
    return 0;
}
