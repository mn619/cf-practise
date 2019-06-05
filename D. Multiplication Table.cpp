#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m,k;

	
int bs(int l,int r)
{
	//cout<<l<<" "<<r<<" "<<"\n";
	int mid=(l+r)/2;
	if(l==r)return mid;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=min((mid-1)/i,m);
	
	if(cnt<k)return bs(mid+1,r);
	return bs(l,mid);
}

signed main()
{
	cin>>n>>m>>k;
	cout<<bs(1,n*m+1)-1;
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

