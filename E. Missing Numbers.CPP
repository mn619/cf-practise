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

int x[200001], n;
vector < pair<int, int> > v[200001];

bool comp(pair <int, int> p1, pair<int, int> p2)
{
	return (p1.second < p2.second);
}

void compute(int ind)
{
	int val = x[ind];

	fr(i,1, sqrt(val))
	{
		if(val%i == 0 && ((i%2) == ((val/i)%2)))
		{	
			v[ind].pb({(i + val/i)/2, (val/i - i)/2});
		}
	}
}
signed main()
{
	//FILEIO
 	start_routine
	
	cin>>n;
	x[0] = 0;
	v[0].pb({0,0});

	fr(i,1,n/2 + 1)
	{
		cin>>x[2*i];
		compute(2*i);
		if(v[2*i].size() == 0)return cout<<"No\n",0;
	}

	fr(i,1,n + 1)
		sort(v[i].begin(), v[i].end(), comp);

	int s = 0;
	fr(i,1,n + 1)
	{
		if(i&1)
		{
			bool ok = 0;
			fr(j,0,v[i + 1].size())
			{
				if(v[i + 1][j].second*v[i + 1][j].second > s)
				{
					ok = 1;
					x[i] = v[i + 1][j].second*v[i + 1][j].second - s;
					break;
				}
			}
			if(!ok) return cout<<"No\n",0;
		}
		s+= x[i];
	}

	cout<<"Yes\n";
	fr(i,1,n + 1)cout<<x[i]<<' ';
	
 	end_routine
}
