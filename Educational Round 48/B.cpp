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
string s,t;
int n,m,q;

signed main()
{
 	//start_routine
	cin>>n>>m>>q;
	cin>>s>>t;
	int ans[n+1] = {0};
	int i;

	fr(i,0,n)
	{
		int j;
		bool b = 1;
		fr(j,0,m)
		{
			if(i+j>=n)
				{
					b = 0;
					break;
				}

			if(s[i+j] != t[j] )
			{
				b = 0;
				break;
			}
		}
		if(b)
			{
				ans[i]++;
			}
	}
	fr(i,1,n)
	{
		ans[i]+=ans[i-1];
	}

	while(q--)
	{
		int l,r;

		cin>>l>>r;
		l--,r--;
		
		if(r-m+1<0)cout<<0<<'\n';
		else if(l-1<0)cout<<ans[r-m+1]<<'\n';
		else
		{
			int temp = ans[r-m+1]-ans[l-1];
			if(temp <= 0)cout<<0<<'\n';
			else cout<<temp<<'\n';
		}

	}
 	//end_routine
}

