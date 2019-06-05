#include<bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define readAndSolve signed main(){read(); solve();}


using namespace std;
int n,m,x[1000001];
bool b[3163]={0};
map <int,int> cnt;

void compute()
{
	for(int i=2;i<=sqrt(10000000);i++)
		if(b[i]==0)
			for(int j=i*i;j<=sqrt(10000000);j+=i)b[j]=1;
}

void f()
{
	vector <int> v;
	for(int i=2;i<=sqrt(10000000);i++)if(b[i]==0)v.pb(i);
	
	for(int i=1;i<=n;i++)
	{
		int temp=i;
		for(int j=0;j<v.size();j++)
		{
			if(i%v[j]==0){cnt[v[j]]++;while(temp%v[j]==0)temp/=v[j];}
			if(temp==1)break;
		}
		if(temp!=1)cnt[temp]++;
	}
	cnt[0]=0;
}
int read()
{
	compute();
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	
	f();
}

int solve()
{
	int l,r;
	map <int,int>::iterator it=cnt.begin(),it1=cnt.begin();
	it++;
	
	while(it!=cnt.end())
	{
		cout<<it->first<<"\n";
		cnt[it->first]+=cnt[it1->first];
		it1++;
		it++;
	}
	cin>>m;
	
	int ans=0;
	while(m--)
	{
		cin>>l>>r;
		it=cnt.lb(l);
		it1=cnt.lb(r);
		it--;
		ans+=(it1->second)-(it->second); cout<< it->first<<"\t"<<it1->first<<"\t"<<ans<<"\n";
	}
	
	cout<<ans<<"\n";
}
readAndSolve

/*
 © Copyright 			all rights reserved
     __           __      __       __    	   __	   _
    //\\         //||    //||     //\\        //||    //
   //  \\       // ||   // ||    //  \\      // ||   //
  //----\\     //  ||  //  ||   //----\\    //  ||  //
 //      \\   //   || //   ||  //      \\  //   || //
//        \\ //    ||//    || //        \\//    ||//

*/

