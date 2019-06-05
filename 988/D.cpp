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
	int n;
	cin>>n;
	vector <int>  v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	
	int l=v[n-1];
	bool tw=0,th=0;
	int x1,x2;
	
	for(int i=0;i<n;i++)
	{
		int k=1;
		while(v[i]+k <=l)
		{
			if(binary_search(v.begin(),v.end(),v[i]+k))
			{
				tw=true;
				x1=v[i],x2=v[i]+k;
				if(binary_search(v.begin(),v.end(),v[i]+2*k))
				{
					return cout<<3<<"\n"<<v[i]<<" "<<v[i]+k<<" "<<v[i]+2*k,0;
				}
			}
			k<<=1;
		}
	}
	
	if(tw)
	{
		cout<<2<<"\n"<<x1<<" "<<x2;
	}
	else cout<<1<<"\n"<<v[0];
	
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

