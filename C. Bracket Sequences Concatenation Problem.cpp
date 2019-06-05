#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define mod 1000000007

using namespace std;
int n,l[300001]={0},r[300001]={0};

void f(string s)
{
	int len=s.size();
	
	if(s[0]==')' && s[len-1]=='(')return;
	
	if(s[0]==')')
	{
		int x=0;
		while(s[x]==')'&&x<len)x++;
		
		int lf=0,rt=0;
		
		for(int i=x;i<len;i++)
		{
			if(s[i]=='(')rt++;
			else lf++;
		}
		int cnt=lf+x-rt;
		if(lf+x>=rt)
		for(int i=0;i<len;i++)
		{
			if(s[i]=='(')cnt++;
			else cnt--;
			if(cnt<0)return;
		}
		if(lf+x>=rt)r[lf+x-rt]++;
		return ;
	}
	
	if(s[len-1]=='(')
	{
		int x=0;
		while(s[len-x-1]=='(')x++;
		
		int lf=0,rt=0;
		
		for(int i=0;i<len-x;i++)
		{
			if(s[i]=='(')rt++;
			else lf++;
			if(lf>rt)return;
		}
		if(rt+x>=lf)l[rt+x-lf]++;
		return;
	}
	
	int lf=0,rt=0;
	for(int i=0;i<len;i++){if(s[i]=='(')rt++;else lf++;}
	if(lf>rt)
	{
		int cnt=lf-rt;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='(')cnt++;
			else cnt--;
			if(cnt<0)return;
		}
		r[lf-rt]++;
	}
	else if(rt>lf)
	{
		int cnt=0;
		for(int i=0;i<len;i++){if(s[i]=='(')cnt++;else cnt--; if(cnt<0)return;}
		l[rt-lf]++;
	}
	else
	{
		int cnt=0;
		for(int i=0;i<len;i++){if(s[i]=='(')cnt++;else cnt--; if(cnt<0)return;}
		l[0]++; r[0]++;
	}
}

signed main()
{
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		f(s[i]);
	}
	int ans=0;
	for(int i=0;i<=300000;i++)ans+=r[i]*l[i];
	cout<<ans;
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
/*
2
())(()(
)
*/
