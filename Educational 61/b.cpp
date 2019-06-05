#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int a[300001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	int n, m, sum = 0;
 	cin>>n;

 	fr(i,1,n + 1)
 	{
 		cin>>a[i]; sum += a[i];
 	}
 	cin>>m;
 	sort(a + 1, a +n + 1);
	reverse(a + 1, a+n +1);
 	
 	fr(i,1,m + 1)
 	{
 		int x;
 		cin>>x;
 		cout<<sum - a[x]<<"\n";
 	}


}