#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,a,b;

void create(bool adj[][2001],int c)
{
	int i=1;
	int x=n;
	while(x>c)
	{
		adj[i][0]=1; adj[0][i]=1; x--;
		i++;
	}
	

}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	bool adj[n][2001]={{0}};
	
	if(a==1 && b==1)
	{
		if(n==2||n==3){cout<<"NO\n";return 0;}
		else
		{
			for(int i=1;i<n-1;i++)
				adj[0][i]=adj[i][0]=1;
				adj[1][n-1]=adj[n-1][1]=1;
			cout<<"YES"<<endl;
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<adj[i][j];
				}
				cout<<endl;
			}
			return 0;
		}
	}
	if(a==1)
	{
		create(adj,b);
	}
	else if(b==1)
	{
		create(adj,a);
	}
	
	
	if(a==1||b==1)
	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) (b==1||i==j)?cout<<adj[i][j]:cout<<!adj[i][j];
			cout<<endl;
		}
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

