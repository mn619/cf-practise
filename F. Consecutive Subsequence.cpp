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
int n,a[200001],b[200001]={0};
signed main()
{
 	start_routine
 	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	map <int,int> dp,m;
	int i;
	fr(i,1,n+1){cin>>a[i]; m[a[i]]=i;}
	fr(i,1,n+1)
	{
		if(dp.count(a[i]-1)) {if(dp[a[i]-1]+1>dp[a[i]])dp[a[i]]=dp[a[i]-1]+1,b[i]=m[a[i]-1];}
		else dp[a[i]]=1,b[i]=i;
	}

	map <int,int> :: iterator it=dp.begin();
	int max=0,st=0;
	while(it!=dp.end())
	{
		if(it->second>max)
		{
			max=it->second;
			st=it->first;
		}
		it++;
	}
	int ans=max;
	cout<<ans<<"\n";
	stack <int> s;
	for(int j=n;j>=1;j--)
	{
		if(a[j]==st){s.push(j);st--;}
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
	end_routine;
}



