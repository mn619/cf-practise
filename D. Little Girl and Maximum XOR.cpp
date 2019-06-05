#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int l,r;
int solve(int a,int b)
{
	int l1=log2(a);
	int l2=log2(b);
	cout<<l1<<"\t"<<l2<<"\t"<<a<<"\t"<<b<<"\n";
	if(l1==l2)return solve(a-pow(2,l1),b-pow(2,l2));
	return (pow(2,max(l1+1,l2+1))-1);
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>l>>r;
	(l==r)?cout<<0<<"\n":cout<<solve(l,r);
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

