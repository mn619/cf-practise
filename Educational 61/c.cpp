#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, q, a[5011] = {0}, b[5011] = {0}, c[5011] = {0};
vector <int> v[5011];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>q;
 	fr(i,1,q +1)
 	{
 		int l ,r;
 		cin>>l>>r;
 		a[l]++, a[r + 1]--;
 		v[i].pb(l);
 		v[i].pb(r);
 	}
 	sort(v + 1, v + q + 1);
 	int used = 0;
 	fr(i,1,n + 1)
 	{
 		b[i] += b[i - 1];
 		c[i] += c[i - 1];

 		a[i] += a[i - 1];
 		if(a[i] > 0) used++;
 		if(a[i] == 1) b[i]++;
 		if(a[i] == 2) c[i]++;
 	}

 	int ans = 0;
 	fr(i,1,q + 1)
 	{
 		fr(j,i + 1, q + 1)
 		{
 			if(v[i][1] < v[j][0])
 			{
 				ans = max(ans, used - (b[v[j][1]] - b[v[j][0] - 1] + b[v[i][1]] - b[v[i][0] - 1]));
 			}
 			else
 			{
 				int r1 = min(v[i][1], v[j][1]), r2 = max(v[i][1], v[j][1]);
 				ans = max(ans, used - (b[v[j][0] - 1] - b[v[i][0] - 1] + c[r1] - c[v[j][0] - 1] + b[r2] - b[r1 - 1]));
 			}
 		}
 	}
 	cout<<ans<<"\n";
}