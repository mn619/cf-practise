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
#define fs first
#define sc second
vector < pair<string, int> > v[101];
string s[201];
int ans[200], n;

bool solve(string p1, string s1, string p2, string s2)
{
	string x1 = p1;
	x1 += s1;

	string x2 = p2;
	x2 += s2;

	if(x1 == x2)
	{
		return 1;
	}
	return 0;
}

bool pcheck(string p, string  x)
{
	int i;
	fr(i,0,p.size())
	{
		if(p[i] != x[i]) return 0;
	}
	return 1;
}

bool scheck(string sf, string x)
{
	int i;
	int len = sf.size() - 1;
	int len2 = x.size() - 1;
	fr(i,0,sf.size())
	{
		if(sf[len - i] != x[len2 - i]) return 0;
	}
	return 1;
}
bool check(string p1, string s1)
{
	string x = p1;
	x+= s1;
	int i;
	fr(i,1,n)
	{
		if(pcheck(v[i][0].fs, x) && scheck(v[i][1].fs,x))
		{
			ans[v[i][0].sc] = 0, ans[v[i][1].sc] = 1;
		}
		else if(scheck(v[i][0].fs, x) && pcheck(v[i][1].fs,x))
		{
			ans[v[i][0].sc] = 1, ans[v[i][1].sc] = 0;
		}
		else return 0;
	}
	return 1;
}

//abab

signed main()
{
	//FILEIO
 	start_routine

	cin>>n;
	int i;
	fr(i,1,2*n - 1)
	{
		cin>>s[i];
		v[s[i].size()].pb({s[i],i});
	}

	bool ok = 0;
	fr(i,0,2)
	{
		int j;
		fr(j,0,2)
		{
			if(solve(v[1][i].fs, v[n - 1][j].fs, v[n - 1][!j].fs, v[1][!i].fs))
			{
				if(check(v[1][i].fs, v[n - 1][j].fs))
				{
					ok = 1;
					break;
				}
			}
		}
		if(ok) break;
	}


	fr(i,1,2*n - 1) 
	{
		if(ans[i]) cout<<"S";
		else cout<<"P";
	}
	
 	end_routine
}
