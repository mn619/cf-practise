#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, a[1001] = {0}, b[1001] = {0};
char c[1001][1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m;

 	fr(i,1,n + 1)
 	{
 		fr(j,1,m + 1)
 		{
 			cin>>c[i][j];
 		}
 	}

 	fr(i,1,n + 1)
 	{
 		fr(j,1,m + 1)
 		{
 			if(c[i][j] == '<') b[j] = min(b[j], a[i] - 1);
 			else if(c[i][j] == '>')
 		}
 	}


}