#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
string s;int n;
void pre(int prefixarr[])
{
	int j=0,i=1;
	prefixarr[0]=0;
	while(i<n)
	{
		if(s[i]==s[j])prefixarr[i++]=++j;
		else
		{
			if(j!=0)
			{j=prefixarr[j-1];}
			else prefixarr[i]=0,i++;
		}
	}
}

int solve(int prefixarr[])
{
	if(prefixarr[n-1]==0)return 0;
	for(int i=1;i<n-1;i++)
	{
		if(prefixarr[i]==prefixarr[n-1])return i;
	}
	if(prefixarr[prefixarr[n-1]-1]==0)return 0;
	
	for(int i=1;i<n-1;i++)
	{
		if(prefixarr[i]==prefixarr[prefixarr[n-1]-1]) return i;
	}
}

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	n=s.size();
	int prefixarr[n+1]={0};
	pre(prefixarr);
	
	int ans=solve(prefixarr);
	
	ans==0?cout<<"Just a legend\n":cout<<s.substr(0,prefixarr[ans]);
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

