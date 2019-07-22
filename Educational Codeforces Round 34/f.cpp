#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/output.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/input.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	srand(time(0));
 	int n = 200000;

 	cout<<n<<'\n';
 	fr(i, 1, n + 1) cout<<((rand()*rand())%mod + mod)%mod + mod/2<<" ";
}