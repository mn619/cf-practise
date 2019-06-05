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

int n,m;

typedef vector<int> VI;

VI mr, mc;
vector <int> w[1000001];

bool FindMatch(int i, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(VI &mr, VI &mc) {
  mr = VI(m*n, -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < n*m; i++) {
    VI seen(w[0].size());
    if (FindMatch(i, mr, mc, seen)) ct++;
  }
  return ct;
}

int f(int i, int j)
{
	return m*(i - 1) + j;
}

signed main()
{
	//FILEIO
 	//start_routine
	cin>>n>>m;

	int i;
	fr(i,1,n + 1)
	{
		int j;
		fr(j,1,m + 1)
		{
			if(i - 1 >= 1)
			{
				if(j - 2 >= 1)
				{
					w[f(i,j)].pb(f(i - 1, j - 2));
				}
				if(j + 2 <= m)
				{
					w[f(i,j)].pb(f(i - 1, j + 2));
				}
			}
			if(i + 1 <= n)
			{
				if(j - 2 >= 1)
				{
					w[f(i,j)].pb(f(i + 1, j - 2));
				}
				if(j + 2 <= m)
				{
					w[f(i,j)].pb(f(i + 1, j + 2));
				}
			}
			if(j - 1 >= 1)
			{
				if(i - 2 >= 1)
				{
					w[f(i,j)].pb(f(i - 2, j - 1));
				}
				if(i + 2 <= m)
				{
					w[f(i,j)].pb(f(i + 2, j - 1));
				}
			}
			if(j + 1 <= m)
			{
				if(i - 2 >= 1)
				{
					w[f(i,j)].pb(f(i - 2, j + 1));
				}
				if(i + 2 <= m)
				{
					w[f(i,j)].pb(f(i + 2, j + 1));
				}
			}
		}
	}
	int ans = BipartiteMatching(&mr,&mc);
 	//end_routine
}
