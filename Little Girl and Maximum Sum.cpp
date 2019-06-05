#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair

using namespace std;
int n,q;
int a[200001],cnt[200001]={0};
void read()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		cnt[l]++;
		cnt[r+1]--;
	}
}

void solve()
{
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	sort(cnt+1,cnt+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=cnt[i]*a[i];
	cout<<ans;
}
signed main()
{
	read();
	solve();
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

