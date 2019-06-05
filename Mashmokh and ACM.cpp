#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n=2000,k;
int dp[2001][2001];
void read() {cin>>n>>k;}
void solve()
{
	int ans=0;
	for(int i=n;i>n/2;i--)
	{
		for(int j=1;j<=k;j++)dp[i][j]=1;
	}
	
	for(int i=1;i<=n/2;i++)dp[i][1]=1;
	
	for(int i=n/2;i>=1;i--)
	{
		for(int j=2;j<=k;j++)
		{
			int temp=0;
			int k=1;
			while(i*k<=n)temp=(temp+dp[i*k++][j-1])%mod;
			dp[i][j]=temp;
		}
		ans=(ans+dp[i][k])%mod;
	}
	

	cout<<(mod+ans+n-n/2)%mod;
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read(); solve();
}

/*
 © Copyright 			all rights reserved
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

