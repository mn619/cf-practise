#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n+1];

	
	ll b[1000001]={1,1};
	
	for(int i=1;i*i<1000000;i++)
	{
		b[i*i]=1;
	}
	
	ll max=-1000000;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0 || b[a[i]]==0)
		{
			if(a[i]>max) max=a[i];
		}
	}
	
	cout<<max<<endl;
}

