#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,p[51],lft=0,ans[5]={0};
vector <int> c[5];

void helpMe(int j)
{
	ans[c[j][1]]+=lft/c[j][0];
	lft=lft%c[j][0];
	if(j!=0)helpMe(j-1);
}
void read()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<5;i++)
	{
		int t;
		cin>>t;
		c[i].pb(t);
		c[i].pb(i);
	}
	
	sort(c,c+5);
	
	for(int i=0;i<n;i++)
	{
		lft+=p[i];
		helpMe(4);
	}
	
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	for(int i=0;i<5;i++)cout<<ans[i]<<" ";
	cout<<"\n"<<lft;
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

