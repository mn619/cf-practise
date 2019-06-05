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
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	string s[n+1];
	vector <int> v[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		v[i].pb(s[i].size());
		v[i].pb(i);
	}
	
	sort(v+1,v+1+n);
	
	bool b=1;
	for(int i=1;i<n;i++)
	{
		if (s[v[i+1][1]].find(s[v[i][1]]) == std::string::npos) 
		{
    		b=0; break;
		}
	}
	
	if(b==0)cout<<"NO\n";
	else 
	{
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
		{
			cout<<s[v[i][1]]<<"\n";
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

