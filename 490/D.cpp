#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,m,a[200010];
	
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int i,rem[m]={0};
	fr(i,0,n){cin>>a[i]; a[i]=(a[i]+m)%m;}
	fr(i,0,n)cout<<a[i]<<" ";
	cout<<"\n";
	fr(i,0,n)rem[a[i]]++;
	sort(rem,rem+m);
	fr(i,0,m)cout<<rem[i]<<" ";
	cout<<"\n";
	int ans=0;
	fr(i,0,m)ans+=abs(rem[i]-n/m);
	cout<<ans/2;
}



