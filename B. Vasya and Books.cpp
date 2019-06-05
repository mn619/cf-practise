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

int n,a[200001], b[200001];

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
		fr(i,1,n+1)
		{
			cin>>a[i];
		}	

		fr(i,1,n+1)
		{
			cin>>b[i];
		}

		map <int,int> m;
		stack <int> s;
		for(i = n; i>=1; i--)
		{
			m[a[i]] = n;
			s.push(a[i]);
		}

		fr(i,1,n+1)
		{
			int cnt  = 0;
			if(m[b[i]] != 0)
			{
				while(1)
				{
					int x = s.top();
					s.pop();
					m[x] = 0;
					cnt++;
					if(x == b[i])  break;
				}
			}
				cout<<cnt<<" ";
		}

	}

 	//end_routine
}
