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

int n, a[2*100001];
vector <int> cnt;

void f()
{
	map <int, int> m;
	int i;

	fr(i,1,n+1)
	 	m[a[i]]++;

	for(auto x: m)
		cnt.pb(x.second);
}

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n;
		int i;
		fr(i,1,n+1) cin>>a[i];
		sort(a + 1, a + 1 + n);
		//fr(i,1,n+1)cout<<a[i]<<" ";
		f();

		int len = cnt.size();
		int ans = 0;

		fr(i,1,cnt[0] + 1)
		{
			int s = i;
			int ans1 = s;

			int l = 1, r = len - 1;
			while(1)
			{
				s*=2;
				int t = 0;

				int l1 = l, r1 = len - 1;

				while(l1 <= r1)
				{
					int mid = (l1 + r1)>>1;
					if(cnt[mid] >= s)
					{
						t = mid;
						r1 = mid - 1;
					}
					else l1 = mid + 1;
				}
				if(t == 0) break;
				ans1 += s;
				l = t + 1;
			}
			ans = max(ans, ans1);
		}

		cout<<ans<<'\n';
	}

 	//end_routine
}
