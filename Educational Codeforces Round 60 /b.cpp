#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n,m,k;
 	cin>>n>>m>>k;
 	int a[n + 1];
 	fr(i,1,n + 1) cin>>a[i];

 	sort(a + 1, a +n + 1);

 	int m1 = a[n], m2 = a[n-1];
 	int t = m/(k  +1);
 	int s = m%(k + 1);

	int ans = t*(k*m1 + m2) + s*m1; 	
 	cout<<ans<<'\n';

}