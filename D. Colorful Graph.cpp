#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m,clr[100001];

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>clr[i];
	
	map <int,set <int> > g;
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(clr[x]!=clr[y])
		g[clr[x]].insert(clr[y]),g[clr[y]].insert(clr[x]);
	}
	
	map <int,set<int> > ::iterator it=g.begin();
	int ans=100000;
	for(int i=1;i<=n;i++)if(clr[i]<ans)ans=clr[i];
	
	if(g.size()!=0)
	while(it!=g.end())
	{
		if(it->second.size() > g[ans].size())ans=it->first;
		it++;
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

