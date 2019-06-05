#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;

vector <int> primes;

void compute()
{
	int k=sqrt(100000)+1;
	bool b[k]={0};
	for(int i=2;i<=k;i++)if(b[i]==0)for(int j=i*i;j<=k;j+=i)b[j]=1;
	
	for(int i=2;i<=k;i++)if(b[i]==0)primes.pb(i);
}

int mx[100001]={0};
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)a[i]=i;
	
	compute();
	
	int dp[n+1];
	for(int i=1;i<=n;i++)
	{
		int temp=a[i];
		dp[i]=0;
		for(int j=0;j<primes.size();j++)
		{
			if(temp%primes[j]==0)
			{
				if(dp[i]<mx[primes[j]]+1){dp[i]=mx[primes[j]]+1;}
				while(temp%primes[j]==0)temp=temp/primes[j];
			}
		}
		if(temp!=1)
		{
			if(dp[i]<mx[temp]+1)dp[i]=mx[temp]+1;
			mx[temp]=max(mx[temp],dp[i]);
		}
		temp=a[i];
		
		for(int j=0;j<primes.size();j++)
		{
			if(temp%primes[j]==0){mx[primes[j]]=max(mx[primes[j]],dp[i]);}
		}
	}
		int ans=0;
		if(n==1&&a[1]==1)return cout<<1,0;
		for(int i=1;i<=n;i++)if(dp[i]>ans)ans=dp[i];;
		cout<<ans; 
		
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

