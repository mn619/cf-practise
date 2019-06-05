#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define f(p,n) for(int i=p;i<n;i++)


using namespace std;

signed main()
{
 	
	float p,d,t,f,c;
	cin>>p>>d>>t>>f>>c;
	
	float k=d-p,st=p*t;
	int ans=0;
	
	if(k>0)
	while(1)
	{
		if(st+st/k*p>=c)break;
		else st+=st/k*p;
		st=st+p*(st/d+f);
		ans++;
	}
	cout<<ans;
}


