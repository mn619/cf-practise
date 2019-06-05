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
int a[100001];
signed main()
{
 	//start_routine
 	int i;
 	cin>>n;
 	fr(i,1,n+1)cin>>a[i];
 	sort(a+1,a+n+1);

 	priority_queue <int> q;

 	int ans=0;
 	q.push(-a[1]);
 	fr(i,2,n+1)
 	{
 		q.push(-a[i]);
 		if(-a[i]<
 			q.top())
 		{
 			ans++;
 			q.pop();
 		}
 	}
 	cout<<ans;
 	//end_routine
}



