#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 998244353

using namespace std;
int n,a[1001], fac[1001]={1},ifac[1001]={1};
int power(int a,int b,int m)
{
	if(b==0)return 1;
	int temp=power(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)temp=(temp*a)%m;
	return temp;
}
void compute()
{
	int i;
	fr(i,1,1000)fac[i]=(fac[i-1]*i)%mod,ifac[i]=power(fac[i],mod-2,mod)%mod;
}
int C(int n,int r)
{
	if(r<0||r>n)return 0;
	int ans=fac[n];
	ans*=ifac[n-r];
	ans%=mod;
	ans*=ifac[r];
	ans%=mod;
	return ans;
}
signed main()
{
 	//start_routine
 	compute();
 	cin>>n;
 	int i;
 	fr(i,0,n)cin>>a[i];
 	int dp[n+2];
 	dp[n+1]=dp[n]=0;
 	for(int i=n-1;i>=0;i--)
 	{
 		dp[i]=dp[i+1];
 		if(a[i]<=0)continue;
 		int j=i+a[i];
 		int temp=0;
 		for(;j<n;j++)
 		{
 			temp+=(C(j-i-1,a[i]-1)*(dp[j+1]+1))%mod;
 		}
 		dp[i]+=temp;
 		dp[i]%=mod;
 	}

 	cout<<(dp[0]+mod)%mod;
	//end_routine
}



