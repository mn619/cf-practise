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
int n,a[200001],ans[200001][2];
bool vis[200001][2]={{0}};

using namespace std;

int f(int i, bool b)
{

	if(i<=0||i>n)return 0;
	if(vis[i][b])return ans[i][b];
	int k;
	vis[i][b]=1,ans[i][b]=-1;
	if(b)
	{
		k=f(i-a[i],!b);
	}
	else k=f(i+a[i],!b);
	if(k!=-1)ans[i][b]=k+a[i];
	else ans[i][b]=-1;
	return ans[i][b];
}
signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,2,n+1)cin>>a[i];
 	fr(i,2,n+1)
 	{
 		ans[i][1]=f(i,1);
 		if(ans[i][1]!=-1)cout<<ans[i][1]+i-1<<"\n";
 		else cout<<-1<<"\n";
 	}
	//end_routine
}



