#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
ll a,b,ans=-2,n;
void solve(ll arr[],ll h,ll w,ll i)
{
	if(i<ans) return;
	//if(((n-1-ans)>34&&ans!=-1)&&(h<a||w<b))return;
	if(h>=a&&w>=b){ans=max(ans,i); return;}
	if(h>=b&&w>=a){ans=max(ans,i); return;}
	
	if(arr[i]==2)
	{
		ll k=(a%h!=0)?a/h+1:a/h;
		ll kk=(b%w!=0)?b/w+1:b/w;
		
		if(h<a&&w<b)
		{
			ll x=i;
			i=i-ceil(log2(k))-ceil(log2(kk));ans=max(ans,i);
			ll as=(b%h!=0)?b/h+1:b/h;
			ll df=(a%w!=0)?a/w+1:a/w;
			x=x-ceil(log2(as))-ceil(log2(df));ans=max(ans,x);
		}
		
		else if(h<a)
		{
			i=i-ceil(log2(k)); ans=max(ans,i);
		}
		else if(w<b)
		{
			i=i-ceil(log2(kk)); ans=max(ans,i);
		}
		
		
		
		//cout<<a/h<<" "<<b/w<<endl;
		//cout<<i<<"\t"<<ceil(log2(ceil(a/h)))<<"\t"<<ceil(log2(ceil(b/w)))<<"\t\n\n";
		return;
	}
	
	if(h<a&&w<b)
	{
		solve(arr,h*arr[i],w,i-1);
		solve(arr,h,arr[i]*w,i-1);
		return;
	}
	
	if(h<a){solve(arr,h*arr[i],w,i-1); return;}
	else solve(arr,h,w*arr[i],i-1);
}

int main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 	
	ll h=1,w=1;n=100;
	a=100000; b=100000;
	cin>>a>>b>>h>>w>>n;
	ll arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	

	
	solve(arr,h,w,n-1);
	//cout<<ans;
	(ans!=-2)?cout<<(n-ans)-1:cout<<-1;
	
}
