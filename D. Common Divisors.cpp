#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
string s1,s2;
gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
bool check(int l)
{	
	for(int i=0;i<l;i++)if(s1[i]!=s2[i])return 0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s1[i%l])return 0;
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]!=s2[i%l])return 0;
	}
	return 1;
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s1>>s2;
	int m=s1.size(),n=s2.size();
	int g=gcd(m,n);
	int ans=0;
	for(int i=1;i<=g;i++)
	{
		if(g%i==0)if(check(i))ans++;
	}
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

