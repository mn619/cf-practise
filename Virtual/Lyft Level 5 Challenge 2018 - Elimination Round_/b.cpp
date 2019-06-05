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

 	int t;
 	cin>>t;

 	while(t--){
 		int a, b;
 		cin>>a>>b;
 		if(a - b != 1){
 			cout<<"NO\n";
 			continue;
 		}
 		else{
 			bool ok = 1;
 			for(int i = 2; i*i <= a + b; i++){
 				if((a + b)%i == 0){
 					ok = 0;
 				}
 			}
 			if(ok) cout<<"YES\n";
 			else cout<<"NO\n";
 		}

 	}

}