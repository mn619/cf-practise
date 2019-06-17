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
	
	char c[n]; int x[n];
	int a=0,b=1023;
	
	
	for(int i=0;i<n;i++)
	{
		cin>>c[i]>>x[i];
		if(c[i]=='&')a&=x[i],b=b&x[i];
		else if(c[i]=='^')a=a^x[i],b=b^x[i];
		else {a|=x[i]; b|=x[i];}
	}
	
	int nd=1023,aur=0,xr=0;
	
	for(int i=0;i<10;i++)
	{
		
		if(a%2==0 && b%2==0)
		{
			nd-=pow(2,i);
		}
		else if(a%2==1 && b%2==1)
		{
			aur+=pow(2,i);
		}
		else if(a%2==1&&b%2==0)
		{
			xr+=pow(2,i);
		}
		b/=2; a/=2;
	}
	
	cout<<3<<"\n";
	cout<<"| "; cout<<aur<<"\n^ "<<xr<<"\n& "<<nd<<"\n";
	
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

