#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n,p,q;
	cin>>n>>p>>q;
	int a[n],b[n],c[n];
	
	for(int i=0;i<2*n;i++)
	{
		if(i<n)cin>>a[i];
		else cin>>b[i%n];
	}
	
	for(int i=0;i<n;i++)
	{
		int k=a[i]-b[i];
		(k>=0)?c[i]=k:c[i]=-k;
	}
	sort(c,c+n);
	
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<endl;
	}
	
	int m=p+q;
	int i=n-1;
	while(m--)
	{
		if(c[i]>c[i-1]&& i>0)c[i]--;
		else if(i==0 && c[i]>0)c[i]--;
		else if(i>0)i--;
		else 
		{
			if(i==0 && c[i]==0)
			{
				
				if(m%2==0)
				{
					cout<<0<<endl;
					return 0;
				}
				else
				{
					cout<<1<<endl;
					return 0;
				}
			}
		}
		
	}
	
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=c[i]*c[i];
		cout<<c[i]<<endl;
	}
	cout<<ans;
}

