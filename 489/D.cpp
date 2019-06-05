#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,k;
int a[200010];
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	queue <int> q;
	int mul=1,sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mul*=a[i];
		sum+=k*a[i];
		q.push(a[i]);
		cout<<q.front()<<"\n";
		if(mul==sum)
		{
			ans++;
		}
		else if(mul>sum)
		{
			mul/=q.front();
			sum-=k*q.front();
			q.pop();
		}
		
	}
	cout<<ans;
}



