#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define rf(i,b,a) for(i=b;i>a;i--)
#define mod 1000000007

using namespace std;
int n,a[200010],ans[200010]={0};

signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,0,n)cin>>a[i];
 	int l[n],r[n];
 	stack <int> s;
 	fr(i,0,n)
 	{
 		while(!s.empty() && a[s.top()]>=a[i])s.pop();
 		if(s.empty())l[i]=0;
 		else l[i]=s.top()+1;
 		s.push(i);
 	}
 	while(!s.empty())s.pop();
 	rf(i,n-1,-1)
 	{
 		while(!s.empty() &&  a[i]<=a[s.top()])s.pop();
 		if(s.empty())r[i]=n-1;
 		else r[i]=s.top()-1;
 		s.push(i);
 	}
 	int len[n];
 	fr(i,0,n)len[i]=r[i]-l[i]+1;
 	fr(i,0,n)ans[len[i]]=max(ans[len[i]],a[i]);
 	rf(i,n-1,-1)ans[i]=max(ans[i],ans[i+1]);

 	fr(i,1,n+1)cout<<ans[i]<<" ";
	//end_routine
}



