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
int n,m,a[100001],b[100001],d[100001];

signed main()
{
 	//start_routine
 	cin>>n>>m;
 	int i,sum = 0;
 	fr(i,0,n)
 	{
 		cin>>a[i]>>b[i];
 		d[i] = a[i] - b[i];
 		sum+=a[i];
 	}
 	if(sum<=m)return cout<<0,0;
 	sort(d,d+n);
 	reverse(d,d+n);
 	int req = sum-m;
 	int ans = 0;
 	fr(i,0,n)
 	{
 		if(req<=0)
 		{
 			cout<<ans;
 			return 0;
 		}
 		req-=d[i];
 		ans++;
 	}
 	if(req<=0){cout<<ans;return 0;}
 	cout<<-1;
 	//end_routine
}



