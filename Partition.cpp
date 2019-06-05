#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int unsigned long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,k,w[222222],fac[222222],ifac[222222],c=0;

int power(int a,int b)
{
	if (b==0)
	return 1;
	int m=mod;
	int temp = power(a,b/2);
	temp = (temp*temp)%m;
	if (b&1)
	return (temp*(a%m))%m; 
	return temp;
}

int solve()
{
	fac[0]=ifac[0]=1;
	for(int i=1;i<=200010;i++)
		fac[i]=(fac[i-1]*i)%mod,ifac[i]=power(fac[i],mod-2)%mod;
	
	for(int i=1;i<=n-k+1;i++)
	{
		int temp=0;
		
		for(int j=0;j<=k-1;j++)
		{
			int temp2=1;
			temp2=(ifac[j]*ifac[k-1-j])%mod;
			temp2=(temp2*power(j,n-i))%mod;
			if((k-1+j)%2) temp2*=-1;
			temp=(temp+temp2)%mod;
		}
		
		temp=(temp*i)%mod;
		temp=(temp*fac[n-1])%mod;
		temp=(temp*ifac[i-1])%mod;
		temp=(temp*ifac[n-i])%mod;
		//cout<<i<<"\t"<<temp<<"\n";
		c=(c+temp)%mod;
	}
	int sum=0;
	for(int i=1;i<=n;i++)sum=(sum+w[i])%mod;
	cout<<(c*sum)%mod;
}
int read()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>w[i];
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

