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
	int a[n+1];
	int per[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		per[a[i]]=i;
	}
	int count=0;
	bool in[n+1]={0};
	int ord=0;
	//for(int i=1;i<=n;i++)cout<<per[i]<<" ";
	
	while(count<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				int j=i,temp=0;
				while(1)
				{
					in[j]=1;
					j=per[j];
					temp++;
					count++;
					if(j==i)break;
				}
				if(temp%2==0)ord++;
			}
		}
	}
	
	if(ord%2==n%2)cout<<"Petr\n";
	else cout<<"Um_nik\n";
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

