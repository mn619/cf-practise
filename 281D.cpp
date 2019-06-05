#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int n;
	cin>>n;
	ll a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	ll max1, max2, ans, x, i1 , i2;
	if(a[0]>a[1]){max1=a[0]; max2=a[1]; i1=0; i2=1;}
	else 
	{
		max1=a[1]; max2=a[0]; i1=1; i2=0;
	}
	ans=max1^max2;
	
	for(int i=2;i<n;i++)
	{
		x=a[i];
		if(x>max1)
		{
			if(i1<i2)
			{
				ll k=max1^x;
				
				if(k>ans)
				{
					ll temp=max1;
					max1=x;
					max2=max1;

					i2=i1;
					i1=x;
				}
				
				k=max2^x;
				if(k>ans)
				{
					max1=x;
					
					i1=i;
				}
			}
		}
		
		else if(x>max2)
		{	if(i2>i1)
			{
				ll k=max2^x;
				if(k>ans)
				{
					max1=x;
					i1=i;
				}
			}
			
		}	
		
		else
		{
			
		}
	}	
	cout<<ans<<"\n";
}

