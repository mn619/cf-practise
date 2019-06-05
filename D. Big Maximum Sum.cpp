#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

vector <int> a[51];
int l[51], ind[250001];
int n,m, preMax[51] = {0}, sufMax[51] = {0}, sum[51] = {0}, subSum[50];

int f(int t)
{
	int ans = -1000, sum = 0;
	fr(i,0,l[t])
	{
		sum += a[t][i];
		ans = max(ans, sum);
		if(sum < 0) sum = 0;
	}
	return ans;
}

int calcPre(int t)
{
	int ans = -1000, sum = 0;
	fr(i,0,l[t])
	{
		sum += a[t][i];
		ans = max(ans, sum);
	}
	return ans;
}

int calcSuf(int t)
{
	int ans = -1000, sum = 0;
	for(int i = l[t] - 1; i>=0; i--)
	{
		sum += a[t][i];
		ans = max(ans, sum);
	}
	return ans;
}

signed main()
{
	//FILEIO
 	start_routine
	cin>>n>>m;
	fr(i,1,n + 1)		
	{
		cin>>l[i];
		fr(j,1,l[i] + 1)
		{
			int x;
			cin>>x;
			sum[i] += x;
			a[i].pb(x);
		}
	}

	fr(i,1,m + 1)cin>>ind[i];

	int ans = -1000;
	fr(i,1,n + 1)
	{
		subSum[i] = f(i);
 	}

 	fr(i,1,m + 1) ans = max(ans, subSum[ind[i]]);

	fr(i,1,n + 1)
	{
		preMax[i] = calcPre(i);
		sufMax[i] = calcSuf(i);
	}

	int msum = sufMax[ind[1]];

	fr(i,2,m + 1)
	{
		msum += preMax[ind[i]];
		ans = max(ans, msum);
		msum += sum[ind[i]] - preMax[ind[i]];
		ans = max(ans, msum);
		if(msum < sufMax[ind[i]]) msum = sufMax[ind[i]];
	}

	cout<<ans<<"\n";
 	end_routine
}
