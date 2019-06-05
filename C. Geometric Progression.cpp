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
int n,k;
int a[200001], pre[200001], post[200001];

signed main()
{
 	start_routine
 	cin>>n>>k;
 	int i;
 	fr(i,0,n)cin>>a[i];
 	map <int,int> premap,postmap;
 	int pre[n] ={0},post[n]={0};

 	fr(i,0,n)
 	{
 		if(a[i]%k==0)
 		{
 			pre[i] = premap[a[i]/k];
 		}
 		premap[a[i]]++;
 	}
 	for(i = n-1;i>=0;i--)
 	{
 		if(a[i]%k==0)post[i]=postmap[a[i]*k];
 		postmap[a[i]]++;
 	}

 	int ans = 0;
 	fr(i,1,n-1){ans+=pre[i]*post[i];}
 	cout<<ans;
 	end_routine
}



