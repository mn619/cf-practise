#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,a[100001];

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	map <int,bool> m;
	int mx=0,cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		a[i]=2000000000;
		int k=a[i];
		if(m.count(a[i]))
		while(m.count(k+1))
		{
			m.erase(k);
			cnt--;
			if(m.count(k+1)&&mx<k+1)mx=k+1;
			k++;
		}
		else m[a[i]]=1,cnt++;
		if(mx<a[i])mx=a[i];
	}
	cout<<mx-cnt+1;
	
	
	
	
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

