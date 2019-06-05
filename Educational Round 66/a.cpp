#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n, k;

void solve(){
	cin>>n>>k;

	int ans = 0;

	while(n){
		if(n%k != 0){
			ans += n%k;
			n -= n%k;
		}
		else if(n > 0) {n /= k; ans++;}
		
	}	
	cout<<ans<<'\n';
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	int t;
 	cin>>t;
 	while(t--){
 		solve();
 	}
}