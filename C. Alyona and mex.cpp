#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m;
vector <int> a[100010];
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n+2;i++)
	{
		a[i].pb(0);
		a[i].pb(i);
	}
	for(int i=1;i<=n+2;i++)cout<<a[i][0];cout<<"\n";
	
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		
		a[l][0]++;
		a[r+1][0]--;
	}
	for(int i=1;i<=n;i++)cout<<a[i][0]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++)a[i][0]+=a[i-1][0];
	for(int i=1;i<=n;i++)cout<<a[i][0]<<" ";
	
	sort(a+1,a+n+1);
	int ans[n+1];
	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		ans[a[i][1]]=n-i;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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

