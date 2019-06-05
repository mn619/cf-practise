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

 	int a ,b;
 	cin>>a>>b;

 	if(b - a >= 10) return cout<<0, 0;
 	int ans = 1;
 	fr(i, a + 1, b + 1){
 		ans *= i;
 		ans %= 10;

 	}

 	cout<<ans;

}	