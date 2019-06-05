#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int a[1001]={0,0,3};
	
	for(int i=3;i<=1000;i++)
	{
		a[i]=(2*a[i-1]+3*a[i-2])%1000000007;
	}
	
	int n;
	cin>>n;
	cout<<a[n]<<endl;
	
	
	 	
}
