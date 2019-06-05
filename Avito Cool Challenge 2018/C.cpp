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

int n, a[100001], b[100001];
vector <int> v[100001];

signed main()
{
	//FILEIO
 	//start_routine
	cin>>n;
	int i;
	fr(i,1,n +1)
	{
		cin>>a[i];
		v[a[i]].pb(i);
	}

	bool ok = 1;
	int clr = 1;
	fr(i,0,100001)
	{
		if(!v[i].empty())
		{
			int k = v[i].size();

			int j;
			if(k%(n - i) != 0)
			{
				ok = 0;
				break;
			}
			int t = k/(n - i);
			int temp = 1;
			j = 0;
			while(temp <= t)
			{
				while(j < temp*(n -i))
				{
					b[v[i][j]] = clr;
					j++;
				}
				clr++;
				temp++;
			}
		}
	}
	if(ok)
	{
		cout<<"Possible\n";
		fr(i,1,n + 1)cout<<b[i]<<" ";
	}
	else cout<<"Impossible";


 	//end_routine
}
