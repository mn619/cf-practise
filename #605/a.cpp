#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn + 2], p[maxn + 2], s[maxn + 2];
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	int las = 1, ans = 0;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		if(a[i] > a[i - 1]) p[i] = i - las + 1;
 		else{
 			las = i;
 			p[i] = 1;
 		}
 		ans = max(ans, p[i]);
 	}		
 	las = n;
 	for(int i = n; i >= 1; i--){
 		if(a[i] < a[i + 1]) s[i] = las - i + 1;
 		else las = i, s[i] = 1;
 	}

 	fr(i, 2, n){
 		if(a[i - 1] >= a[i + 1]) continue;	
 		ans = max(ans, p[i - 1] + s[i + 1]);
 	}

 	cout<<ans;
}