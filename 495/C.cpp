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
int a[100005],cnt[100005]={0};
signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,0,n){cin>>a[i];}
 	set <int> s;
 	for(int i=n-1;i>=0;i--)
 	{
 		if(!s.empty())cnt[i]=s.size();
 		else cnt[i]=0;
 		s.insert(a[i]);
 	}
 	set <int> s2;
 	int ans=0;
 	fr(i,0,n)
 	{
 		if(s2.count(a[i]))continue;
 		s2.insert(a[i]);
 		ans+=cnt[i];
 	}
 	cout<<ans;

	//end_routine
}



