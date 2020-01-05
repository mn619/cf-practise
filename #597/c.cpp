#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int f[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	string s;
 	cin>>s;

 	int ans = 1;

 	f[0] = 1;
 	f[1] = 1;

 	fr(i, 2, maxn){
 		f[i] = (f[i - 1] + f[i - 2])%mod;
 	}

 	int cntu = 0, cntn = 0;
 	fr(i, 0, s.size()){
 		if(s[i] != 'u'){
 			ans *= f[cntu];
 			cntu = 0;
 		}
 		else cntu++;
 		if(s[i] != 'n'){
 			ans *= f[cntn];
 			cntn = 0;
 		}
 		else cntn++;
 		ans %= mod;
 		if(s[i] == 'm' || s[i] == 'w') ans = 0;
  	}
 	ans *= f[cntn];
 	ans *= f[cntu];
 	ans %= mod;

 	cout<<ans<<'\n';
}