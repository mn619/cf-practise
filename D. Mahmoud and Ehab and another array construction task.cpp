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

int a[100001], n;
int b[100001];
vector <int> d[100001];

set <int> s;

int gcd(int a, int b)
{
	if(b == 0)return a;
	return gcd(b, a%b);
}

void  compute()
{
	bitset <2000001> p;
	int i;
	fr(i,2,2000001) 
	{
		if(p[i] == 0)
		{
			s.insert(i);
			int j;
			for(j = 2*i; j<2000001; j+=i) p[j] = 1;
		}
	}

	bitset <100001> pp;
	fr(i,2,100001)
	{
		if(pp[i] == 0)
		{
			d[i].pb(i);
			int j;
			for(j = 2*i; j<=100000; j+=i)
			{
				p[j] = 1;
				d[j].pb(i);
			}
		}
	}
}

signed main()
{
	compute();
	cin>>n;
	int i;
	fr(i,1,n+1)cin>>a[i];
	b[1] = a[1];

	fr(i,2,n)
	{
		bool ok = 1;
		int x = a[i];
		int j;
		fr(j,0,d[x].size())
		{
			if(s.find(d[x][j]) == s.end())
			{
				ok = 0;
				break;
			}
			else s.erase(d[x][j]);
		}
		if(ok) b[i] = a[i];
		else break;
	}

	
}
