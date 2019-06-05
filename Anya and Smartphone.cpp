#include<bits/stdc++.h>
#define int long long


using namespace std;
int n,m,k;
map <int,int> pos,icon;
void read()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int temp; cin>>temp; pos[temp]=i; icon[i]=temp;
	}
}
void solve()
{
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int queri;
		cin>>queri;
		ans+=-(pos[queri]%k==0)+pos[queri]/k;
		int temp=icon[pos[queri]];
		if(pos[queri]!=1)icon[pos[queri]]=icon[pos[queri]-1],icon[pos[queri]-1]=temp,pos[icon[pos[queri]]]=pos[queri],pos[icon[pos[queri]-1]]=pos[queri]-1;
	}
	cout<<ans+m;
}
signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read(),solve();
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

