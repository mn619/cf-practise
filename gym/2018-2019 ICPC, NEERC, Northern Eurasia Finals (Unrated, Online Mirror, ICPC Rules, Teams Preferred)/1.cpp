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

int k, a[8] = {1};

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		cin>>k;
		int i;
		int s = 0;
		fr(i,0,7) {cin>>a[i]; s+=a[i];}
		int ans = 7*(k/s);
		k %= s;

		if(k == 0)
		{
			ans -= 7;
			k = s;
		}

		int temp = 8;
		fr(i,0,7)
		{
			int d = i;
			int cnt = 0;
			int j;
			
			fr(j,1,8)
			{
				cnt += a[(i + j + 7)%7];
				if(cnt == k) break;
			}
			temp = min(temp, j);
		}
		ans += temp;
		cout<<ans<<'\n';
	}

 	//end_routine
}
