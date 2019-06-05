#include<bits/stdc++.h>
#define int long long
#define f(p,n) for(int i=p;i<n;i++)

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int p[n/2+1];
	for(int i=1;i<=n/2;i++)cin>>p[i];
	sort(p+1,p+1+n/2);
	
	int ans=0;
	for(int i=1;i<=n/2;i++)
	{
		ans=ans+abs(p[i]-2*i);
	}
	int temp=0;
	
	for(int i=1;i<=n/2;i++)
	{
		temp=temp+abs(p[i]-2*i+1);
	}
	if(temp<ans)ans=temp;
	cout<<ans;
}


