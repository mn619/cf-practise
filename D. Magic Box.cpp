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
	int x,y,z,x1,y1,z1,a[7];
	cin>>x>>y>>z>>x1>>y1>>z1>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
	
	int ans=0;
	if(y<0)ans+=a[1];
	else if(y>y1)ans+=a[2];
	if(z<0)ans+=a[3];
	else if(z>z1)ans+=a[4];
	if(x<0)ans+=a[5];
	else if(x>x1)ans+=a[6];
	cout<<ans<<"\n";
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

