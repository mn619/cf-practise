#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,m;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int x[10],y[10],b[10]={0},c[10]={0};
	for( int i=0;i<n;i++){cin>>x[i]; b[x[i]]=1;};
	for(int i=0;i<m;i++)
	{
		cin>>y[i];
		c[y[i]]=1;
	}
	
	for(int i=0;i<n;i++)if(b[x[i]]&&c[x[i]])cout<<x[i]<<" ";
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

