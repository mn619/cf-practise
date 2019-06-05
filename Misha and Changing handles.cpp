#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair

using namespace std;

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	string ol[n],ne[n];
	map <string,string> m;
	
	for(int i=0;i<n;i++)
	{
		cin>>ol[i]>>ne[i];
		m[ol[i]]=ne[i];
	}
	map<string,string> ans;
	int j=0;
	
	map <string,bool> mp;
	for(int i=0;i<n;i++)
	{
		if(mp.count(ol[i])==0)
		{
			string s=ol[i];
			while(1)
			{
				mp[s]=1;
				if(m.count(s))s=m[s];
				else break;
			}
			ans[ol[i]]=s;
		}
	}
	map <string,string> ::iterator it=ans.begin();
	cout<<ans.size()<<"\n";
	while(1)
	{
		cout<<it->first<<" "<<it->second<<"\n";
		it++;
		if(it==ans.end())break;
	}
}

/*
Proudly Created by
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

