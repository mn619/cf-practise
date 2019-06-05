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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n,m,a[100011], pre[100011] = {0}, suf[100012] = {0};
signed main()
{
	//FILEIO
 	//start_routine

	cin>>n>>m;
	int i;
	int sum = 0;
	fr(i,1,n +1) {cin>>a[i]; sum += a[i];}

	if(n == 1)
	{
		return cout<<m,0;
	}
	fr(i,1,n +1) pre[i] = pre[i - 1] + a[i];

	for(i = n; i>=1; i--)
	{
		suf[i] = suf[i + 1] + a[i];
	}
	fr(i,1,n +1)
	{
		int temp = sum - a[i] + m;
		if(max(pre[i - 1], suf[i + 1]) > temp)
		{
			temp = max(pre[i - 1], suf[i + 1]);
		}
		cout<<temp<<" ";
	}


 	//end_routine
}
