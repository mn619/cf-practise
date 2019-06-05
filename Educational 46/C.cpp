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
int l[200001],r[200001];
signed main()
{
 	//start_routine
 	int i;
 	cin>>n;
 	map<int, int> ml,mr;
 	vector <int> coord;
 	fr(i,0,n){cin>>l[i]>>r[i];coord.pb(l[i]); coord.pb(r[i]+1); ml[l[i]]++; mr[r[i]+1]--;}
	sort(coord.begin(), coord.end());
	int cnt=ml[coord[0]]+mr[coord[0]];
	coord.pb(-1);
 	int ans[n+1]={0};
 	ml[-1]=mr[-1]=0;
 	fr(i,1,2*n)
 	{
 		if(coord[i]!=coord[i-1]){ans[cnt]+=coord[i]-coord[i-1]; cnt+=ml[coord[i]]+mr[coord[i]];}
 	}
 	fr(i,1,n+1)cout<<ans[i]<<" ";
 	
	//end_routine
}



