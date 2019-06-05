#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
int n,m, a[100001],c[100001],t[100001],d[100001], ans[100001] = {0};
vector <int> v[100001];

signed main()
{
	//FILEIO
 	FLASH
	cin>>n>>m;

	fr(i,1,n + 1)
	{
		cin>>a[i];
	}
	fr(i,1,n + 1) 
	{
		cin>>c[i]; 
		v[i].pb(c[i]); 
		v[i].pb(i);
	}

	sort(v + 1, v + n + 1);
	

	fr(i,1,m + 1)
	{
		cin>>t[i]>>d[i];
	}

	int dish = 1, cust = 1;

	while(dish <= n && cust <= m)
	{
		int x = t[cust], y = d[cust];
		if(a[x] > 0)
		{
			int temp = min(y, a[x]);
			a[x] -= temp;
			y -= temp;
			ans[cust] += temp*c[x];
		}
		if(y > 0)
		{
			while(y > 0 && dish <= n)
			{
				int temp = min(y, a[v[dish][1]]);

				a[v[dish][1]] -= temp;
				y -= temp;
				ans[cust] += temp*v[dish][0];
				if(a[v[dish][1]] == 0) dish++;
			}
		}
		if(y > 0) {ans[cust] = 0; break;}
		cust++;
	}

	fr(i,1,m + 1) cout<<ans[i]<<"\n";


}