// be name khoda
#include<iostream>
#include<cstring>

using namespace std;
int arr[200], arr1[200], arr2[200];
int main(){
	arr[1]=1;
	int siz = 3;
	for(int i=1; i< 10 ; i++)
	{	
		int cnt=0;
		for(int j=1;j< siz+2 ; j++)
		{
			arr1[j] = ((arr[j] * (j%10) ) + cnt) % 10;
			cnt = ((arr[j]* (j%10)) + cnt) / 10 ;	
		//	cout<<arr1[j]<<endl;
		}
		 cnt=0;
		for(int j= 1; j < (siz+2) ; j++)
		{
			arr2[j+1]=((arr[j]*(j/10))+cnt) % 10;
			cnt = ((arr[j] * ( j/10)) + cnt) / 10 ;
		}
		 cnt=0;
		for(int j=1; j <  (siz +3) ; j++)
		{
			arr[j]=(arr1[j]+arr2[j] + cnt)%10;
			cnt= (arr1[j]+arr2[j]+cnt) / 10;

		}
		for(int kk=1;kk<siz;kk++)
			cout<< arr[kk];
		cout<<endl;
		for(int j=0 ; j<200 ; j++)
		{
			arr1[j]=0;
			arr2[j]=0;
		}
		siz+=2;
	}
	int ans=0;
	for(int i=1;i<200;i++)
		ans= ans+ arr[i];
	cout<<ans;
	cin>>ans;
}
