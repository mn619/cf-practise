#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n;
int solve(int l,int r)
{
	if(r<=l)return l;
	
	int k=(l+r)/2;
	int cnt=0,temp=n;
	while(temp>0)
	{
		cnt+=min(temp,k);
		temp-=k;
		temp=temp-temp/10;
	}
	if(n%2)
	{
		if(cnt>=n/2+1){if(r==l+1) return l; else return solve(l,k);}
		else return solve(k+1,r);
	}
	else
	{
		if(cnt>=n/2){if(r==l+1)return l; else return solve(l,k);}
		else return solve(k+1,r);
	}
	
}
signed main()
{
 	//start_routine
 	cin>>n;
 	if(n<=10)return cout<<1,0;
 	int k=solve(1,n);
 	if(k==1)return cout<<1,0;
 	int temp=k-1,temp2=n;
 	int cnt=0;
 	while(temp2>0)
 	{
 		cnt+=min(temp2,temp);
 		temp2-=temp;
 		temp2=temp2-temp2/10;
	}
	if(n%2)
	{
		if(cnt>=n/2+1) return cout<<temp<<"\n",0;
	}
	else
	{
		if(cnt>=n/2)return cout<<temp<<"\n",0;
	}
 	cout<<k;
	//end_routine
}

