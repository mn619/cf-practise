#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
solve(ll b[], ll n)
{
	ll d=b[1]-b[0];
	
	
	int ans=0;
	for(int i=2;i<n;i++)
	{
		if(b[i]==b[0]+i*d) continue;
		else if(b[i]==b[0]+d*i+1 || b[i]==b[0]+d*i-1)
		{
			ans++;
		}
		else return -1;
	}
	return ans;
}
int main()
{
	ll n;
	cin>>n;
	ll b[n];
	int ans=1000001;
	for(int i=0;i<n;i++)cin>>b[i];
	ll k;
	b[0]--; b[1]--;
	
	k=solve(b,n);
	if(ans>k+2 && k!=-1)ans=k+2;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k+1 && k!=-1)ans=k+1;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k+2 && k!=-1)ans=k+2;
		
	b[0]++; b[1]-=2;
	k=solve(b,n);
	if(ans>k+1 && k!=-1)ans=k+1;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k && k!=-1)ans=k;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k+1 && k!=-1)ans=k+1;
	
	
	b[0]++; b[1]-=2;
	k=solve(b,n);
	if(ans>k+2 && k!=-1)ans=k+2;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k+1 && k!=-1)ans=k+1;
	
	
	b[1]++;
	k=solve(b,n);
	if(ans>k+2 && k!=-1)ans=k+2;
	
					
	(ans==1000001)?cout<<-1<<endl:cout<<ans<<endl;
}


