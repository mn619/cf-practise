#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, m, a[100001][3] = {{0}};
string s;

signed main()
{
	FILEIO
 	FLASH
	cin>>s>>m;
	n = s.size();

	fr(i,0,n)
	{
		if(s[i] == 'z') a[i + 1][0]++;
		if(s[i] == 'y') a[i + 1][1]++;
		if(s[i] == 'x') a[i + 1][2]++;
	}

	fr(i,1,n + 1) 
	{
		fr(j,0,3)
		a[i][j] += (a[i - 1][j]);
	}

	while(m--)
	{
		int l, r, cntz = 0, cnty = 0, cntx = 0;
		cin>>l>>r;
		cntz = a[r][0] - a[l - 1][0];
		cnty = a[r][1] - a[l - 1][1];
		cntx = a[r][2] - a[l - 1][2];

		if(r - l + 1 < 3 || max(cntz, max(cnty, cntx)) - min(cntx, min(cntz, cnty)) <= 1) cout<<"YES\n";
		else  cout<<"NO\n";
	}
}