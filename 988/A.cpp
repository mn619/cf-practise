#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,k;
	cin>>n>>k;
	int a[101]={0};
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		if(a[temp]==0)cnt++;
		a[temp]=i;
	}
	
	int cnt1=0;
	if(cnt<k)cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(int i=1;i<=100;i++)
		{
			if(a[i]!=0)
			{
				cnt1++;
				cout<<a[i]<<" ";
			}
			
			if(cnt1==k)break;
		}
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

