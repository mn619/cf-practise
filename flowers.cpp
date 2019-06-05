#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int f[100005]={0};
int n,k;
compute()
{
	for(int i=1;i<=100000;i++)
	{
		if(i<k)f[i]=1;
		else if(i==k)f[k]=2;
		else f[i]=(f[i-1]+f[i-k])%mod;
		
	}
	
	for(int i=1;i<=100000;i++)
	{
		f[i]=(f[i]+f[i-1])%mod;
	}
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int a,b;
	compute();
	while(n--)
	{
		cin>>a>>b;
		(f[b]-f[a-1]<0)?cout<<mod+f[b]-f[a-1]<<"\n":cout<<f[b]-f[a-1]<<"\n";
	}
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

