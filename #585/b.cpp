#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn + 1], even = 0, odd = 0, k= 0;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	int ans = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		if(a[i] < 0){
 			k ^= 1;
 		}
 		if(k){
 			odd++;
 			ans += even + 1;
 		}
 		else { 
 			even++;
 			ans += odd; 
 		}
 	}

 	cout<<ans<<" "<<n*(n+1)/2-ans;
 	
}