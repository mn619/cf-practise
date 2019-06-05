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
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001];
vector <int> v[200001];
map <int, int> s[200001];
int ans = 0;

int gcd(int a, int b)
{
	if(b == 0)return a;
	return gcd(b, a%b);
}

void dfs(int node, int parent)
{


	s[node][a[node]] = 1;
	if(a[node] > 1) ans = max(ans, (int)1);

	if(parent != 0)
	{
		for(auto it : s[parent])
		{
			int g = gcd(a[node], it.first);
			if(s[node].count(g) ==0 ) s[node][g] = it.second + 1;
			else s[node][g] = max(s[node][g], it.second + 1);

			if(g > 1) ans = max(ans, it.second + 1);
		}
	}

	fr(i,0,v[node].size())
	{
		if(v[node][i] == parent) continue;
		dfs(v[node][i], node);
	}
}

signed main()
{
	//FILEIO
 	start_routine
	

	cin>>n;
	
	fr(i,1,n + 1)
	{
		cin>>a[i];
	}

	fr(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1,0);

	cout<<ans;
 	end_routine
}