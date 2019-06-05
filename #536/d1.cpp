#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
vector <int> v[100001];
map<pair<int, int>, bool> ed;

int n,m;
signed main()
{
	//FILEIO
 	FLASH
	cin>>n>>m;
	fr(i,1,m + 1)
	{
		int a,b;
		cin>>a>>b;
		if(ed[{a,b}] == 0)
		{
			ed[{a,b}] = 1;
			ed[{b,a}] = 1;
			v[a].pb(b);
			v[b].pb(a);
		}
	}

	priority_queue <int> pq;
	vector <int> ans;
	int node = 1;
	pq.push(-node);
	bool in[n + 1] = {0};

	while(ans.size() < n)
	{
		node = -pq.top();
		ans.pb(node);
		in[node] = 1;
		pq.pop();
		fr(i,0,v[node].size())
		{
			if(in[v[node][i]] == 0) {in[v[node][i]] = 1; pq.push(-v[node][i]);}
		}
	}

	fr(i,0,n) cout<<ans[i]<<" ";
}