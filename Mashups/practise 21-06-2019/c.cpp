#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int k, b, n, t;
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 		
 	cin>>k>>b>>t>>n;

 	if(k == 1){
 		int ans = (1 + t*b - n)/b + ((1 + t*b - n)%b != 0);
 		ans = max(ans, (int) 0);
 		cout<<ans;
 		return 0;
 	}

 	int ans = 0;
 	int pwr = 1;

 	while(pwr*(k - 1 + b) < (n*(k - 1) + b) and ans < t){
 		pwr *= k;
 		ans++;
 	}

 	cout<<t - ans;
}