#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair

using namespace std;

signed main()
{
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int cost[n];
	vector <int> s[n],c[n];
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		s[i].pb(temp);
		s[i].pb(i);
	}

	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		cost[i]=temp;
		c[i].pb(temp);
		c[i].pb(i);
	}
	
	sort(c,c+n);
	int i1=-1,i2=-1,i3=-1;
	for(int i=0;i<n;i++)
	{
		bool b=0;
		for(int j=i+1;j<n;j++)
		{
			if(c[i][1]<c[j][1] && s[c[i][1]][0]<s[c[j][1]][0])
			{
				i1=c[i][1],i2=c[j][1];  b=1; break;
			}
			if(c[j][1]<c[i][1] && s[c[j][1]][0]<s[c[i][1]][0])
			{
				i1=c[j][1],i2=c[i][1];  b=1; break;
			}
			
		}
		if(b)break;
	}
	if(i1==-1)
	{
		cout<<-1;
	}
	else
	{
		int temp=s[i2][0];
		int min=100000000000,mindex=-1;
		for(int i=i2+1;i<n;i++)
		{
			if(s[i2][0]<s[i][0])
			{
				if(cost[i]<min)
				{
					mindex=i;
					min=cost[i];
				}
			}
		}
		
		for(int i=0;i<i1;i++)
		{
			if(s[i1][0]>s[i][0])
			{
				if(cost[i]<min)
				{
					mindex=i;
					min=cost[i];
				}
			}
		}
		
		for(int i=i1+1;i<i2;i++)
		{
			if(s[i1][0]<s[i][0] && s[i][0]<s[i2][0])
			{
				if(cost[i]<min)
				{
					mindex=i;
					min=cost[i];
				}
			}
		}
		
		i3=mindex;
		
		if(i1==-1||i3==-1)cout<<-1;
		else
		{
			cout<<cost[i1]+cost[i2]+cost[i3];
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

