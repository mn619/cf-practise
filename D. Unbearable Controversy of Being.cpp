#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m;
vector <int> v[3001];
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
	}
	int adj[n+1][n+1]={0};
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=0;k<v[v[i][j]].size();k++)
				adj[i][v[v[i][j]][k]]++;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j)ans+=(adj[i][j]-1)*adj[i][j]/2;
	
	
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

