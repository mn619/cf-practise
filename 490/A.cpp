#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,k;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int a[101];
	
	int i;
	fr(i,0,n)
	{
		cin>>a[i];
	}
	i=0;
	int cnt=0;
	while(i<n)
	{
		if(a[i]<=k)cnt++;
		else break;
		i++;
	}
	int j=i;
	i=n-1;
	while(i>=j)
	{
		if(a[i]<=k)cnt++;
		else break;
		i--;
	}
	
	cout<<cnt;
}
