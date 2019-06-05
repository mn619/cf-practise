#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,m,a[1501];

signed main()
{
 	start_routine
 	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	int p[n+1],i;
	fr(i,1,n+1){cin>>a[i]; p[a[i]]=i;}
	int cnt=0,in[n+1]={0},ans=0;
	
	fr(i,1,n+1)
	{
		int temp=0,j=i;
		if(!in[i])
		while(!in[j])
		{
			in[j]=1;
			j=p[j];
			temp++;
		}
		if(!temp%2)cnt++;
	}
	if(cnt%2)ans=1;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int s=r-l+1;
		if(s/2 %2 )ans=(ans+1)%2;
		if(ans%2)cout<<"odd\n";
		else cout<<"even\n";
	}
	end_routine;
}



