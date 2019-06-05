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
signed main()
{
 	//start_routine
	
	int n;
	cin>>n;
	vector <int> le(n);
	vector <int> r(n);
	vector < pair<int,int> > sum(n);
	vector <int> ans(n);

	int i;
	fr(i,0,n) cin>>le[i];
	fr(i,0,n){cin>>r[i];sum[i].first = le[i] + r[i], sum[i].second = i;}

	sort(sum.begin(), sum.end());
	int j = n;
	bool k = 1;

	fr(i,0,n)
	{
		if(sum[i].first == sum[i-1].first)
		{
			ans[sum[i].second] = j;
		}
		else 
		{
			j--;
			ans[sum[i].second] = j;
		}
	}

	int left, right;
	bool q = 1;
	fr(i,0,n)
	{
		left = 0, right = 0;
		int p;
		fr(p,0,n)
		{
			if(p<i)
			{
				if(ans[p] > ans[i])
					left++;
			}
			else if(p>i)
			{
				if(ans[p] > ans[i])
				right++;
			}
			
		}
		if(left!=le[i] || right!=r[i])
				k=0;

	}
		if(k)
		{
			cout<<"YES\n";
			int ad = 1;
			fr(i,0,n)
			{
				ad = min(ad , ans[i]);
			}
			if(ad == 0) ad = 1;
			else ad = 0;
			fr(i,0,n) cout<<ans[i]+ad<<" ";
		}
		else 
		{
			cout<<"NO\n";
		}
		return 0;

 	//end_routine
}
