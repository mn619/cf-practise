#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;


int x[8],y[8],area,area1;

bool in(int sq, int xx,int yy)
{
	if(sq==0)
	{
		int s=abs(xx*x[1]-x[0]*yy+x[0]*x[3]-x[1]*x[2]-xx*x[3]+yy*x[2]);
		s+=abs(xx*x[3]-x[2]*yy+x[2]*x[5]-x[3]*x[4]-xx*x[5]+yy*x[4]);
		s+=abs(xx*x[5]-x[4]*yy+x[4]*x[7]-x[5]*x[6]-xx*x[7]+yy*x[6]);
		s+=abs(xx*x[1]-x[0]*yy+x[0]*x[7]-x[1]*x[6]-xx*x[7]+yy*x[6]);
		//cout<<sq<<"\t"<<s<<"\n";
		if(s>area*2)return 0;
		return 1;
	}
	
	if(sq==1)
	{
		//cout<<xx<<"\t"<<yy<<"\n";
		int s=abs(xx*y[1]-y[0]*yy+y[0]*y[3]-y[1]*y[2]-xx*y[3]+yy*y[2]);
		//cout<<s<<"\t";
		s+=abs(xx*y[3]-y[2]*yy+y[2]*y[5]-y[3]*y[4]-xx*y[5]+yy*y[4]);
		//cout<<s<<"\t";
		s+=abs(xx*y[5]-y[4]*yy+y[4]*y[7]-y[5]*y[6]-xx*y[7]+yy*y[6]);
		//cout<<s<<"\t";
		s+=abs(xx*y[1]-y[0]*yy+y[0]*y[7]-y[1]*y[6]-xx*y[7]+yy*y[6]);
		//cout<<sq<<"\t"<<s<<"\n";
		if(s>area1*2)return 0;
		return 1;
	}
	
	if(sq==2)
	{
		int s=abs(xx*x[1]-x[0]*yy+4*x[0]*x[3]-4*x[1]*x[2]-xx*x[3]+yy*x[2]);
		s+=abs(xx*x[3]-x[2]*yy+4*x[2]*x[5]-4*x[3]*x[4]-xx*x[5]+yy*x[4]);
		s+=abs(xx*x[5]-x[4]*yy+4*x[4]*x[7]-4*x[5]*x[6]-xx*x[7]+yy*x[6]);
		s+=abs(xx*x[1]-x[0]*yy+4*x[0]*x[7]-4*x[1]*x[6]-xx*x[7]+yy*x[6]);
		//cout<<sq<<"\t"<<s<<"\n";
		if(s>area*8)return 0;
		return 1;
	}
	
	if(sq==3)
	{
		//cout<<xx<<"\t"<<yy<<"\n";
		int s=abs(xx*y[1]-y[0]*yy+4*y[0]*y[3]-4*y[1]*y[2]-xx*y[3]+yy*y[2]);
		//cout<<s<<"\t";
		s+=abs(xx*y[3]-y[2]*yy+4*y[2]*y[5]-4*y[3]*y[4]-xx*y[5]+yy*y[4]);
		//cout<<s<<"\t";
		s+=abs(xx*y[5]-y[4]*yy+4*y[4]*y[7]-4*y[5]*y[6]-xx*y[7]+yy*y[6]);
		//cout<<s<<"\t";
		s+=abs(xx*y[1]-y[0]*yy+4*y[0]*y[7]-4*y[1]*y[6]-xx*y[7]+yy*y[6]);
		//cout<<sq<<"\t"<<s<<"\n";
		if(s>area1*8)return 0;
		return 1;
	}
}
signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i=0;i<8;i++)cin>>x[i];
	for(int i=0;i<8;i++)cin>>y[i];
	
	area=max((x[0]-x[2])*(x[0]-x[2]),(x[0]-x[6])*(x[0]-x[6]));
	area1=(y[3]-y[1])*(y[3]-y[1])+(y[2]-y[0])*(y[2]-y[0]);
	
	for(int i=0;i<4;i++)
	{
		if(in(0,y[2*i],y[2*i+1])) return cout<<"YES\n",0;
	}
	
	for(int i=0;i<4;i++)
	{
		if(in(1,x[2*i],x[2*i+1])) return cout<<"YES\n",0;
	}
	
	if(in(2,y[0]+y[2]+y[4]+y[6],y[1]+y[3]+y[5]+y[7])) return cout<<"YES\n",0;
	if(in(3,x[0]+x[2]+x[4]+x[6],x[1]+x[3]+x[5]+x[7])) return cout<<"YES\n",0;
	return cout<<"NO\n",0;
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

