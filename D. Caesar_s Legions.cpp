#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 100000000

using namespace std;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;

	int dp[n1+1][n2+1][2]={{{0}}};
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	
	dp[0][0][0]=1,dp[0][0][1]=1;

	
	
	if(k1==1&&k2==1)
	{
		if(n1>n2+1||n2>n1+1)return cout<<0,0;
		else if(n1==n2)return cout<<2,0;
		else return cout<<1,0;
	}
	for(int i=1;i<=n1&&i<=k1;i++)dp[i][0][0]=1;
	for(int i=1;i<=n2&&i<=k2;i++)dp[0][i][1]=1;
	
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(i!=0&&j!=0)dp[i][j][0]=0,dp[i][j][1]=0;
			
			for(int k=1;k<=i&&k<=k1;k++)
				dp[i][j][0]+=dp[i-k][j][1],dp[i][j][0]%=mod;

			for(int k=1;k<=j&&k<=k2;k++)
				dp[i][j][1]+=dp[i][j-k][0],dp[i][j][1]%=mod;
		}
	}
	
	cout<<(dp[n1][n2][0]+dp[n1][n2][1]+mod)%mod;
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

