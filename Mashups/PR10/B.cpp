#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int f(int l,int r)
{
	
	if(l==r)return r;
	
	int l2=log2(r),l1=log2(l);
	
	if(pow(2,l2)<=l){
	return f(l-(int)pow(2,l1),r-(int)pow(2,l2))+(int)pow(2,l2);
	}
	else if((int)pow(2,l2+1)-1<=r) return (int)pow(2,l2+1)-1;
	return (int)pow(2,l2)-1;
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 	//cout<<(int)log2((int)1000000000000000000);
	int n;
	cin>>n;
	int l,r;
	while(n--)
	{
		cin>>l>>r;
		cout<<f(l,r)<<"\n";
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

