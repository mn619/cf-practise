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
int n,m;

signed main()
{
 	//start_routine
	cin>>n>>m;
	int l[m],r[m]; vector <int> len[m];
	int ans[n];
	int i;
	fr(i,0,n)ans[i]=-1;
	fr(i,0,m){cin>>l[i]>>r[i]; l[i]--; r[i]--; len[i].pb(r[i]-l[i]+1); len[i].pb(i);}
	sort(len,len+m);
	fr(i,0,m)
	{
		int j;
		int cnt=0;
		if(len[i][0]==1)continue;
		//cout<<l[len[i][1]]<<" "<<r[len[i][1]]<<" "<<len[i][0]<<"\n";
		fr(j,l[len[i][1]],r[len[i][1]]+1)
		{
			if(ans[j]!=-1)cnt+=ans[j];
		}
		int temp;
		if(cnt<len[i][0])temp=1;
		else temp=0;

		fr(j,l[len[i][1]],r[len[i][1]]+1)
		{
			if(ans[j]==-1)
			{
					ans[j]=j%2;
			}
		}
	}
	fr(i,0,n){if(ans[i]==-1)cout<<i%2;else cout<<ans[i];}
	//end_routine
}



