#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int k;
	ll i=19,n,ans;
	cin>>k;
	while(k)
	{
		if(i%9==1)
		{
			n=i;
			ans=n;
			int sum=0;
			while(n!=0)
			{
				sum+=n%10;
				n=n/10;
			}
			if(sum==10){k--; }
		}
		
		i+=9;
	}
	cout<<ans;
}

