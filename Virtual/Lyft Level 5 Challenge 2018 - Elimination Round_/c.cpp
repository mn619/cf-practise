#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, p[100001], inv[100001], ans[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>p[i];
 		inv[p[i]] = i;
 	}

 	ans[n] = 0;
 	for(int i = n - 1; i >= 1; i--){
 		int pos = inv[i];
 		pos %= i;
 		bool ok = 0;
 		while(pos <= n){
 			if(ans[p[pos]] == 0 and p[pos] > i) ok = 1;
 			pos += i;
 		}
 		if(ok) ans[i] = 1;
 		else ans[i] = 0;
 	}

 	fr(i, 1, n + 1){
 		if(ans[p[i]]) cout<<"A";
 		else cout<<"B";
 	}

}