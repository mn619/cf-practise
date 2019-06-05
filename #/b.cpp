#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int n,m,k;
int a[200001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>n>>m>>k;
 	vector <int> v[n+ 1];

 	fr(i,1,n + 1)  {cin>>a[i]; v[i].pb(a[i]); v[i].pb(i);}
 	
 	sort(v + 1, v+ n + 1);
 	reverse(v + 1, v + n + 1);

 	bool in[n + 1] = {0};

 	int cnt = 0, ans = 0;
 	fr(i,1,k*m + 1)
 	{
 		in[v[i][1]] = 1;
 		ans += v[i][0];
 	}

 	cout<<ans<<'\n';
 	int indcnt = 0;
 	fr(i,1,n + 1)
 	{
 		cnt += in[i];
 		if(cnt == m) {cout<<i<<" "; indcnt++; if(indcnt == k - 1) break;cnt = 0;}
 	}
}