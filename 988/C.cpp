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
	int k;
	cin>>k;
	vector <int> v[k+1];
	int len[k+1];
	int sum[k+1];
	for(int i=1;i<=k;i++)
	{
		cin>>len[i];
		int s=0;
		for(int j=0;j<len[i];j++)
		{
			int temp;
			cin>>temp;
			s+=temp;
			v[i].pb(temp);
		}
		sum[i]=s;
	}
	
	map <int,int> m;
	
	int i1,i2,j1,j2;
	bool b=0;
	
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(m.count(sum[i]-v[i][j])==0)m[sum[i]-v[i][j]]=i;
			else if(m[sum[i]-v[i][j]]!=i)
			{
				i1=m[sum[i]-v[i][j]];
				i2=i;
				j2=j+1;
				b=1;
				//cout<<sum[i]-v[i][j]<<"\n"<<m[sum[i]-v[i][j]]<<"\n"<<i<<'\n'<<j<<"\n";
				break;
			}
			
		}
	
		if(b)break;
	}
	if(b)
	for(int j=0;j<v[i1].size();j++)
	{
		if(sum[i1]-v[i1][j]==sum[i2]-v[i2][j2-1])
		{
			j1=j+1;
		}
	}
	
	if(b)
	{
		cout<<"YES\n";
		cout<<i1<<" "<<j1<<"\n"<<i2<<" "<<j2;
	}
	else cout<<"NO\n";
	
	
	
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

