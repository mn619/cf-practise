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

signed main()
{
	FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		int n,k;
		cin>>n>>k;
		int a[n+1], pre[n+1] = {0};
		int i, sum = 0;
		fr(i,1,n+1)
		{
			cin>>a[i];
			pre[i] = pre[i-1] + a[i];
			sum+=a[i];
		}
		if(sum%k != 0)
		{
			cout<<"No\n";
			continue;
		}

		bool b = 1;
		int t = sum/k;
		int c = 1;
		vector <int> ans;
		fr(i,1,n+1)
		{
			if(pre[i]%t == 0 && pre[i]/t == c)
			{
				c++;
				ans.pb(i);
			}
			else if(pre[i] > t*c)
			{
				b = 0;
				break;
			}
		}
		if(b == 0) 
		{
			cout<<"No\n";
			continue;
		}
		int las = 0;
		cout<<"Yes\n";
		fr(i,0,ans.size()) 
		{
			cout<<ans[i]-las<<" ";
			las = ans[i];
		}
		cout<<"\n";

	}

 	//end_routine
}
