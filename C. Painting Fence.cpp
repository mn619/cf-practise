#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n=0,a[5001];
void read(){for(int i=0;i<=n;i++)(i==0)?cin>>n:cin>>a[i];}

int solve(int l,int r,int h)
{
	//cout<<l<<" "<<r<<" "<<h<<"\n";
	if(l>r)return 0;
	if(l==r){return (int) (a[l]-h!=0);}
	
	int hmin=10000000000;
	int mindex;
	
	for(int i=l;i<=r;i++)
	{
		if(a[i]-h<hmin){hmin=a[i]-h; mindex=i;}
	}
	return min(r-l+1,hmin+solve(l,mindex-1,a[mindex])+solve(mindex+1,r,a[mindex]));
}
signed main()
{
 //	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	
	cout<<solve(1,n,0);
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

