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
int k,m;
int a[101]={0};
signed main()
{
 	//start_routine
 	cin>>k>>m;
 	int i;
 	fr(i,0,m)
 	{
 		int x;
 		cin>>x;
 		a[x]++;
 	}
 	vector <int> v;
 	fr(i,1,101)
 	{
 		if(a[i]>0)v.pb(a[i]);
 	}
 	sort(v.begin(),v.end());
 	reverse(v.begin(),v.end());
 	int l = v.size();
 	int ans= 100000;
 	int cnt[l] = {0};
 	i=l-1;
	
 	while(k>0 && ans>0)
 	{
	 	fr(i,0,l)
	 	{
	 		int d = v[i]/(cnt[i]+1);
	 		int maxdex = i;

	 		int j;
	 		fr(j,0,l)
	 		{
	 			if(v[j]/(cnt[j]+1) > d){d = v[j]/(cnt[j]+1); maxdex = j;}
	 		}

	 		ans = d;
	 		cnt[maxdex]++;
	 		k--;
	 		if(k<=0)break;
	 	}
	}
	cout<<ans;
 	//end_routine
}



